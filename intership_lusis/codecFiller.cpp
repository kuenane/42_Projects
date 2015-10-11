#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <sstream>
#include <cstdio>

using namespace std;

static void   check_ac(int ac)
{
  if (ac != 3)
  {
    cout << "usage: ./codecFiller specfile codec.xml" << endl;
    exit(0);
  }
}

static void   open_files(char **av, ifstream &spec, ifstream &codec)
{
  spec.open(av[1], fstream::in);
  if (!spec)
  {
    cout << "error: cannot open spec file" << endl;
    exit(0);
  }
  codec.open(av[2], fstream::in);
  if (!codec)
  {
    spec.close();
    cout << "error: cannot open codec file" << endl;
    exit(0);
  }
}

static bool   check_line(string &line, int lineNb)
{
  if (line.empty())
  {
    cout << "[notice] line " << lineNb << ": empty line ignored" << endl;
    return true;
  }
  if (line.find(' ') != string::npos || line.find('\t') != string::npos)
  {
    cout << "[notice] line " << lineNb << ": contain space/tab automatically removed" << endl;
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
  }
  return (false);
}

static void   split_by_slash(string &line, list<string> &lst, list<string> &lstcp)
{
  istringstream  tmp(line);
  string         linecopy;

  lst.clear();
  lstcp.clear();
  while (getline(tmp, line, '/'))
  {
    linecopy = line;
    lst.push_back(line);
    lstcp.push_back(linecopy);
  }
}

static void   search_in_codec(string &tosearch, int &pos, ifstream &codec)
{
  string    tmp;

  codec.clear();
  (pos == -424242) ? codec.seekg(0, codec.beg) : codec.seekg(pos);
  while (getline(codec, tmp))
  {
    if (tmp.find("<element name=\"" + tosearch + "\"") == tmp.npos
    && tmp.find("<attribute name=\"" + tosearch + "\"") == tmp.npos)
      continue;
    pos = codec.tellg();
    codec.clear();
    codec.seekg(0, codec.beg);
    return ;
  }
  pos = -42;
  codec.clear();
  codec.seekg(0, codec.beg);
}

static int   fill_current_element(ifstream &codec, int &pos, char *av2)
{
  ofstream    tmpfile("tototatatititutu.tmp", ofstream::trunc);
  string      tmpline;
  string      linetomodify;
  bool        founded = false;
  string      linetomodifyname;

  if (!tmpfile)
    return (-1);
  codec.clear();
  codec.seekg(pos);
  getline(codec, linetomodify);
  if (linetomodify.find("name=\"") == linetomodify.npos
  || linetomodify.find("valToField\"\"") == linetomodify.npos)
  {
    tmpfile.close();
    remove("tototatatititutu.tmp");
    codec.clear();
    codec.seekg(0, codec.beg);
    return (0);
  }
  codec.clear();
  codec.seekg(0, codec.beg);
  while (getline(codec, tmpline))
  {
    if (tmpline.empty())
      continue ;
    if (founded || linetomodify.compare(tmpline))
    {
      tmpfile << endl << tmpline;
      tmpline.clear();
    }
    else
    {
      linetomodifyname = linetomodify.substr(linetomodify.find("name=\"") + 6);
      linetomodifyname.erase(linetomodifyname.find_first_of('"'));
      linetomodify.insert(linetomodify.find("valToField=\"") + 12, linetomodifyname);
      tmpfile << endl << linetomodify;
      linetomodify.clear();
      linetomodifyname.clear();
      founded = true;
    }
  }
  tmpfile.close();
  codec.close();
  remove(av2);
  rename("tototatatititutu.tmp", av2);
  codec.open(av2, fstream::in);
  return (0);
}

static void   close_files(ifstream &spec, ifstream &codec)
{
  spec.close();
  codec.close();
}

int           main(int ac, char **av)
{
  ifstream       spec;
  ifstream        codec;
  string         line;
  int            lineNb = 0;
  int            pos;
  list<string>   lst;
  list<string>   lstcp;

  check_ac(ac);
  open_files(av, spec, codec);
  while (getline(spec, line))
  {
    lineNb++;
    pos = -424242;
    if (check_line(line, lineNb))
      continue ;
    split_by_slash(line, lst, lstcp);
    while (!lst.empty())
    {
      search_in_codec(lst.front(), pos, codec);
      if (pos == -42)
      {
        cout << "[error]  line " << lineNb << ": cannot find '" << lst.front() << "' (line ignored)" << endl;
        lstcp.remove(lst.front());
        lst.pop_front();
        break ;
      }
      lst.pop_front();
    }
    pos = -424242;
    while (!lstcp.empty())
    {
      search_in_codec(lstcp.front(), pos, codec);
      if (pos == -42 || fill_current_element(codec, pos, av[2]))
      {
        cout << "[error]  line " << lineNb << ": unknown error when trying to fill '" << lstcp.front() << "' (parents stay filled...)" << endl;
        lstcp.pop_front();
        break ;
      }
      lstcp.pop_front();
    }
  }
  close_files(spec, codec);
  return (0);
}
