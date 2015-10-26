<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>

<xsl:template match="/">
<errors>
<xsl:apply-templates/>
</errors>
</xsl:template>

<xsl:template match="comment()">
</xsl:template>
<xsl:template match="text()">
</xsl:template>



<xsl:template match="*"> 
<xsl:choose>
<!-- exist -->
<xsl:when test="count(preceding-sibling::node()[name()=name(current())])!=0">
<error double="{name(.)}" />
</xsl:when>
<xsl:otherwise>
<xsl:for-each select="./*">
<xsl:apply-templates/>
</xsl:for-each> 
</xsl:otherwise>
</xsl:choose>
</xsl:template>


</xsl:stylesheet>