<?php

######################################################################
# SourceContact: Open Source Contact Management
# =============================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceContact: http://sourcecontact.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This is the text backend of the system
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
###################################################################### 

require("./include/prepend.php3");

page_open(array("sess" => "SourceContact_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceContact_Session",
                  "auth" => "SourceContact_Auth",
                  "perm" => "SourceContact_Perm"));
}
header("Content-Type: text/plain");

// Disabling cache
header("Cache-Control: no-cache, must-revalidate");     // HTTP/1.1
header("Pragma: no-cache");                             // HTTP/1.0

require("./include/config.inc");
require("./include/lib.inc");

$db = new DB_SourceContact;
$db->query("SELECT * FROM contact WHERE contact.status='A' ORDER BY contact.modification DESC limit 10");
$i=0;
while($db->next_record()) {
  echo $db->f("name")."\n";
  $timestamp = mktimestamp($db->f("modification"));
  echo timestr($timestamp)."\n";
  echo $sys_url."conbyconid.php?id=".$db->f("conid")."\n";
  $i++;
} 

@page_close();
?>
