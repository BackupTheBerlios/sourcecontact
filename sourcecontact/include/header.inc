<?php

######################################################################
# SourceContact: Open Source Contact
# ================================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de)
#
# BerliOS SourceContact: http://sourcebiz.berlios.de/contact
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This file contains the common header
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

// Disabling cache
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache"); 				// HTTP/1.0

require("./include/config.inc");
require("./include/lib.inc");
require("./include/translation.inc");
require("./include/lang.inc");
require("./include/box.inc");

// require("/usr/local/httpd/phpAdsNew/phpadsnew.inc.php");

$t = new translation($la);
$db = new DB_SourceContact;
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 TRANSITIONAL//EN">
<html>
<head>
   <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
   <meta http-equiv="expires" content="0">
   <title><?php echo $sys_name;?> - <?php echo $t->translate($sys_title);?></title>
<link rel="STYLESHEET" type="text/css" href="style.php">
<link rel="SHORTCUT ICON" href="favicon.ico">
<SCRIPT LANGUAGE="JavaScript"> function addNetscapePanel() { 
      if ((typeof window.sidebar == "object") && (typeof window.sidebar.addPanel == "function")) 
      { 
         window.sidebar.addPanel ("SourceContact", 
         "<?php echo $sys_url."sitebar.php"?>",""); 
      } 
      else 
      { 
         var rv = window.confirm ("This page is enhanced for use with Netscape 6.  " + "Would you like to upgrade now?"); 
         if (rv) 
            document.location.href = "http://home.netscape.com/download/index.html";
      } 
   } 
//--> </SCRIPT>

</head>
<body bgcolor="<?php echo $th_body_bgcolor;?>" topmargin="0" bottommargin="0" leftmargin="0" rightmargin="0" marginheight="0" marginwidth="0">

<!--
<table align=center BORDER=0 CELLSPACING=4 CELLPADDING=0 >
<tr><td>
<?php
// view('', 2, '_blank', '', '1');
?>
</td><td>
<?php
// view('', 3, '_blank', '', '1');
?>
</td></tr></table>
-->
<?php
require("top_strip.inc");
require("top_title.inc");
?>

<table BORDER=0 CELLSPACING=0 CELLPADDING=0 WIDTH="100%" >
<tr VALIGN=TOP BGCOLOR="<?php echo $th_body_bgcolor;?>">
<td BGCOLOR="<?php echo $th_nav_bgcolor;?>">
<?php
require("menubar.inc");
?>
</td>

<td WIDTH="10"><img SRC="images/blank.gif" BORDER=0 height=1 width=10></td>

<td WIDTH="99%">
<p>&nbsp;
