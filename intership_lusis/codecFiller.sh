#!/bin/bash

if [ "$#" -ne 3 ]; then
	echo "usage: codecFiller.sh specTree codec outfile"	
	exit 1
fi	
if [ ! -f "$1" ]; then
	echo "error: specTree file not found"
	exit 1
fi
if [ ! -f "$2" ]; then
	echo "error: codec file not found"
	exit 1
fi

SPECTMP='SPECTMP.tmp'
XSLTMP='XSLTMP.tmp'
XSLTMP2='XSLTMP2.tmp'
DEFAULTBLOCK='<xsl:template match="/protocol/message/xmlfield/element/element[@name="TOTOTATATITITUTU"]/@valToField | /protocol/message/xmlfield/element/element[@name="TOTOTATATITITUTU"]/@valToField"><xsl:attribute name="valToField"><xsl:choose><xsl:when test="../@busToField">content</xsl:when><xsl:otherwise><xsl:value-of select="../@name"/></xsl:otherwise></xsl:choose></xsl:attribute></xsl:template>'
CODECNAME="$2"
LINENB=0
ERRNB=0
FILLEDNB=0

cp "$1" "$SPECTMP"
cp "$2" "$3"
while IFS='' read -r line || [[ -n "$line" ]]; do
  ((LINENB++))
  NEWLINE=$(echo "$line" | sed "s#/#']/element[@name='#g")
  echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > "$XSLTMP"
  echo "<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">" >> "$XSLTMP"
  echo "<xsl:output method=\"xml\" version=\"1.0\" encoding=\"UTF-8\" indent=\"yes\"/>" >> "$XSLTMP"
  echo "<xsl:template match=\"node()|@*\">" >> "$XSLTMP"
  echo "<xsl:copy>" >> "$XSLTMP"
  echo "<xsl:apply-templates select=\"node()|@*\"/>" >> "$XSLTMP"
  echo "</xsl:copy>" >> "$XSLTMP"
  echo "</xsl:template>" >> "$XSLTMP"
  echo $(echo "$DEFAULTBLOCK" | sed "s#\"TOTOTATATITITUTU\"#'$NEWLINE'#g" | rev | sed "s#=eman@\[tnemele/#=eman@\[etubirtta/#" | rev) >> "$XSLTMP"
  echo "</xsl:stylesheet>" >> "$XSLTMP"
  xsltproc --output "$XSLTMP2" "$XSLTMP" "$3"
  if [ $(grep "valToField" "$XSLTMP2" | grep -v "valToField=\"\"" | wc -l) == $(grep "valToField" "$3" | grep -v "valToField=\"\"" | wc -l) ]; then
    echo "error line $LINENB: $line"
    ((ERRNB++))
  else
    ((FILLEDNB++))
  fi
  cp "$XSLTMP2" "$3"
done < "$SPECTMP"
rm -rf "$SPECTMP" "$XSLTMP" "$XSLTMP2"
if [ "$ERRNB" = 0 ]; then
  echo "--- All the lines filled ($LINENB), no error found ---"
else
  echo ""
  echo "--- $FILLEDNB lines filled on $LINENB ($ERRNB errors) ---"
fi