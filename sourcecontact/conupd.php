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
# Update contact.
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
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
    $be->box_full($t->translate("Error"), $t->translate("Access denied"));
    $auth->logout();
} else {
if (isset($id) ) {
	$columns = "*";
	$tables = "contact";
	$where = "contact.conid = '$id'";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
		mysql_die($db);
	} else {
		$db->next_record();
		if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {
			if (!isset($action)) {
				conmod($db);
			} else {
				$name = trim($name);
				$address = trim($address);
				$country = trim($country);
				$state = trim($state);
				$city = trim($city);
				$zip = trim($zip);
				$phone = trim($phone);
				$fax = trim($fax);
				$email = trim($email);
				$homepage = trim($homepage);
				if (!empty($homepage) && !ereg("^http://", $homepage)) {
					$homepage = "http://".$homepage;
				}
				$comment = trim($comment);
				$status = trim($status);
				if (!empty($name)) {

				$tables = "contact";
				$set = "name='$name',category='$category',address='$address',country='$country',state='$state',city='$city',zip='$zip',phone='$phone',fax='$fax',email='$email',homepage='$homepage',comment='$comment'";
				switch ($action) {
				case "change":
					$set = $set.",status='$status'";
					break;
				case "delete":
					$set = $set.",status='D'";
					break;
				case "undelete":
					$set = $set.",status='A'";
					break;
				case "erase":
					break;
				default:
					$be->box_full($t->translate("Error"), $t->translate("No Action specified"));
					$set = $set.",status='$status'";
					break;
				}
				$where = "conid='$id'";
				if ($action == "erase") {
					$query = "DELETE FROM $tables WHERE $where";
				} else {
					$query = "UPDATE $tables SET $set WHERE $where";
				}
				if ($action == "erase" && !$perm->have_perm("admin")) {
					$be->box_full($t->translate("Error"), $t->translate("Access denied"));
				} else {
					if (!$db->query($query)) {
						mysql_die($db);
					} else {
						if ($action == "erase") {
							erase($id);
							$be->box_full($t->translate("Erase"), $t->translate("Contact")." (ID: $id) ".$t->translate("is erased"));
						} else {
							conbyconid($db,$id);
						}
					}
				}
				} else {
					$be->box_full($t->translate("Error"), $t->translate("No Name specified"));
				}
			}
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Access denied"));
		}
	}
} else {
	$be->box_full($t->translate("Error"), $t->translate("No Contact ID specified"));
}	
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
page_close();
?>
