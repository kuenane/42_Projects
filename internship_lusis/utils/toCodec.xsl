<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="xml" version="1.0" encoding="UTF-8" indent="yes"/>
	<xsl:template match="comment()">
		<xsl:comment>
			<xsl:value-of select="."/>
		</xsl:comment>
	</xsl:template>
	<xsl:template match="text()">
	</xsl:template>
	<xsl:template match="/">
		<protocol name="" defaultMessage="{name(/*)}">
			<type name="LENGTH_TYPE" code="A"/>
			<type name="SEP_TYPE" code="B"/>
			<type name="TAG_TYPE" code="B"/>
			<type name="XML_TYPE" code="A"/>
			<prefield/>
			<message name='{name(/*)}' XML="1">
				<xmlfield name='{name(/*)}' type='A' charset='UTF-8'>
					<xsl:apply-templates/>
				</xmlfield>
			</message>
		</protocol>
	</xsl:template>
	<xsl:template match="*">
		<xsl:choose>
			<!-- chield exist -->
			<xsl:when test="./*">
				<!-- if first element -->
      	<xsl:choose>
					<xsl:when test="ancestor::*">
						<element name="{name(.)}" valToField="" bus="1">
						<xsl:for-each select="./@*">
							<attribute name="{name(.)}" valToField=""/>
						</xsl:for-each>
						<xsl:apply-templates/>
						</element> 					
					</xsl:when>
					<xsl:otherwise>
						<element name="{name(.)}" valToField="">
						<xsl:for-each select="./@*">
							<attribute name="{name(.)}" valToField=""/>
						</xsl:for-each>
						<xsl:apply-templates/>
						</element> 					
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<!-- attribut exist -->
			<xsl:when test="./@*">
				<element name="{name(.)}" busToField="{name(.)}" valToField="" bus="1">
					<xsl:for-each select="./@*">
						<attribute name="{name(.)}" valToField=""/>
					</xsl:for-each>
				</element>
			</xsl:when>
			<!-- attribut exist -->
			<xsl:otherwise>
				<element name="{name(.)}" valToField=""/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
</xsl:stylesheet>
