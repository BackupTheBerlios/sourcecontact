<?php

######################################################################
# SourceBiz: Open Source Contact Management
# =========================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de)
#
# BerliOS SourceContact: http://sourcecontact.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Update classification of user contact
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
require("./include/clalib.inc");
require("./include/perlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<?
if (isset($id) ) {
	$columns = "*";
	$tables = "contact,classifications";
	$where = "contact.conid = classifications.conid AND classifications.type = '$type' AND contact.conid = '$id'";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
		mysql_die($db);
	} else {
		$db->next_record();
		if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {
			if (count($classes) > 0) {
	            $clalist = addslashes(implode($classes,","));
			} else {
				$clalist = "";
			}
			$tables = "classifications";
			$set = "type='$type',class='$clalist'";
			$where = "conid='$id'";
			$query = "UPDATE $tables SET $set WHERE $where";
			if (!$db->query($query)) {
				mysql_die($db);
			} else {
				conbyconid($db,$id);
				if ($ml_notify) {
					$msg = "update classification \"$clalist\" of contact (ID: $id) by ".$auth->auth["uname"].".";
					mailuser("admin", "update classification", $msg);
				}
			}
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Access denied"));
		}
	}
} else {
	$be->box_full($t->translate("Error"), $t->translate("No Contact ID specified"));
}	
?>
<!-- end content -->

<?php
require("./include/footer.inc");
page_close();
?>
