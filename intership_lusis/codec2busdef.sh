#!/bin/bash

#######################################
#########       DEFINES       #########
#######################################

XSLT_TO_APPLY="<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">
  <xsl:output method=\"text\" omit-xml-declaration=\"yes\" indent=\"no\"/>
  <xsl:template match=\"comment()\"></xsl:template>
  <xsl:template match=\"text()\"></xsl:template>
  <xsl:template match=\"*\">
    <xsl:choose>
      <xsl:when test=\"@valToField != ''\">
        <xsl:choose>
          <xsl:when test=\"@bus\">
            <xsl:text>['</xsl:text>
            <xsl:value-of select=\"@name\"/>
            <xsl:text>', 'V', '', [&#10;</xsl:text>
            <xsl:if test=\"./@*\">
              <xsl:apply-templates/>
            </xsl:if>
            <xsl:text>]],&#10;</xsl:text>
          </xsl:when>
          <xsl:when test=\"@occ\">
            <xsl:text>['</xsl:text>
            <xsl:value-of select=\"@name\"/>
            <xsl:text>', 'O', '', [&#10;</xsl:text>
            <xsl:if test=\"./@*\">
              <xsl:apply-templates/>
            </xsl:if>
            <xsl:text>]],&#10;</xsl:text>
          </xsl:when>
          <xsl:otherwise>
            <xsl:text>['</xsl:text>
            <xsl:value-of select=\"@name\"/>
            <xsl:text>', 'Z' ],&#10;</xsl:text>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:when>
      <xsl:otherwise>
        <xsl:for-each select=\"*\">
            <xsl:apply-templates/>
        </xsl:for-each>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
</xsl:stylesheet>"

NB_SPACE_TO_INDENT=2

KEEP_GENERATED_XSL_FILE=0

USAGE_STRING="usage: codec2desc.sh codec [--fulldesc Product_Name]"

XSL_TMPFILE='codec2busdef.xslt.tmp'

DESC_TMPFILE='codec2busdef.desc.tmp'







####################################
#########       MAIN       #########
####################################

if [ "$#" -ne 1 ] && [ "$#" -ne 3 ]; then
  echo "$USAGE_STRING" 
  exit 1
fi

if [ "$#" -eq 3 ]; then
  if [ "$2" = "--fulldesc" ]; then
    FULLDESCOPTION=1
  else
    echo "$USAGE_STRING" 
    exit 1
  fi
else
  FULLDESCOPTION=0
fi

if [ ! -f "$1" ]; then
	echo "error: codec file not found"
	exit 1
fi

if [ "$FULLDESCOPTION" = 1 ]; then
  PNAME_LOW=`echo "$3" | tr '[:upper:]' '[:lower:]'`
  PNAME_UP=`echo "$3" | tr '[:lower:]' '[:upper:]'`
  PNAME_LOW_NOUNDERSCORE=`echo "$3" | tr '[:upper:]' '[:lower:]' | tr -d '_'`
  PNAME_UP_NOUNDERSCORE=`echo "$3" | tr '[:lower:]' '[:upper:]' | tr -d '_'`
  echo "\$produit = '$PNAME_LOW';

%product =
(
  'Pro_tmp'      => '$PNAME_LOW',
  'Protmp'       => '$PNAME_LOW_NOUNDERSCORE',
  'PRO_TMP'      => '$PNAME_UP',
  'PROTMP'       => '$PNAME_UP_NOUNDERSCORE',
  'auteur'       => '`whoami`',
  'V0X.XX'       => 'V01_00',
  'V0Y.YY'       => 'V01_00',
  'AAAA/MM/JJ a HH:MM:SS'       => '`date +%Y/%m/%d`',
);

@cfgdef =
(
);

@busdef =
("
fi

echo "$XSLT_TO_APPLY" > "$XSL_TMPFILE"
xsltproc --output "$DESC_TMPFILE" "$XSL_TMPFILE" "$1"
SPACENB="$NB_SPACE_TO_INDENT"
while IFS='' read -r line || [[ -n "$line" ]]; do
  [[ $line =~ ^\]\],$ ]] && ((SPACENB-=$NB_SPACE_TO_INDENT))
  printf %"$SPACENB"s
  [[ $line =~ .*\[$ ]] && ((SPACENB+=$NB_SPACE_TO_INDENT))
  echo "$line"
done < "$DESC_TMPFILE"
if [ "$FULLDESCOPTION" = 1 ]; then
  echo ");

@session =
(
);

@context = 
(
);

1;"
fi
rm -rf "$DESC_TMPFILE"
if [ "$KEEP_GENERATED_XSL_FILE" -eq 0 ]; then
  rm -rf "$XSL_TMPFILE"
fi