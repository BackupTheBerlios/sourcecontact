<?php

######################################################################
# SourceContact: Open Source Contact Management
# =============================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de)
#
# BerliOS SourceContact: http://sourcecontact.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Adding a contact
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

require("./include/prepend.php3");

page_open(array("sess" => "SourceContact_Session",
                "auth" => "SourceContact_Auth",
                "perm" => "SourceContact_Perm"));

require("./include/header.inc");
require("./include/conlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
	$be->box_full($t->translate("Error"), $t->translate("Access denied"));
	$auth->logout();
} else {
	if (isset($name) && !empty($name)) {
//
// Look if contact is already in table
//
		$name = trim($name);
		$columns = "*";
		$tables = "contact";
		$where = "name='$name'";
		if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
			mysql_die($db);
		} else {
//
// If contact in table show existing values to change
//
			if ($db->next_record()) {
				if (isset($auth) && !empty($auth->auth["perm"]) && ($perm->have_perm("admin") || $db->f("user") == $auth->auth["uname"])) {
					conmod($db);
				} else {
					$be->box_full($t->translate("Error"), $t->translate("Access denied")."<br>".$t->translate("A Contact with this name already exist"));
				}
//
// If contact is not in table, insert it
//
			} else {
				conform($db);
			}
		}
	} else {
		$be->box_full($t->translate("Error"), $t->translate("No Contact Name specified")."."
		."<br>".$t->translate("Please select")." <a href=\"".$sess->url("conform.php")."\">".$t->translate("New Contact")."</a>");
	}
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
page_close();
?>
