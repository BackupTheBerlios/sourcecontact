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
# Update contact person.
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
<?
if (isset($id) ) {
	$columns = "*";
	$tables = "persons,contact";
	$where = "contact.conid = persons.conid_per AND persons.perid = '$id'";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
		mysql_die($db);
	} else {
		$db->next_record();
		if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {
			if (!isset($action)) {
				permod($db);
			} else {
				$salutation_per = trim($salutation_per);
				$firstname_per = trim($firstname_per);
				$lastname_per = trim($lastname_per);
				$grad_per = trim($grad_per);
				$position_per = trim($position_per);
				$phone_per = trim($phone_per);
				$fax_per = trim($fax_per);
				$email_per = trim($email_per);
				$homepage_per = trim($homepage_per);
				if (!empty($homepage_per) && !ereg("^http://", $homepage_per)) {
					$homepage_per = "http://".$homepage_per;
				}
				$comment_per = trim($comment_per);
				$status_per = trim($status_per);
				if (!empty($lastname_per)) {

				$tables = "persons";
				$set = "salutation_per='$salutation_per',firstname_per='$firstname_per',lastname_per='$lastname_per',grad_per='$grad_per',position_per='$position_per',phone_per='$phone_per',fax_per='$fax_per',email_per='$email_per',homepage_per='$homepage_per',comment_per='$comment_per'";
				$where = "perid='$id'";
				switch ($action) {
				case "change":
					$set = $set.",status_per='$status_per'";
					break;
				case "delete":
					$set = $set.",status_per='D'";
					break;
				case "undelete":
					$set = $set.",status_per='A'";
					break;
				case "erase":
					break;
				default:
					$be->box_full($t->translate("Error"), $t->translate("No Action specified"));
					$set = $set.",status_per='$status_per'";
					break;
				}
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
							$be->box_full($t->translate("Erase"), $t->translate("Contact Person")." (ID: $id) ".$t->translate("is erased"));
						} else {
							conbyperid($db,$id);
							perbyperid($db,$id);
						}
						if ($ml_notify) {
							$msg = "$action contact person \"$firstname_per $lastname_per\" of contact (ID: $id) by ".$auth->auth["uname"].".";
							mailuser("admin", "$action contact person", $msg);
						}
					}
				}
				} else {
					$be->box_full($t->translate("Error"), $t->translate("No LastName specified"));
				}
			}
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Access denied"));
		}	
	}
} else {
	$be->box_full($t->translate("Error"), $t->translate("No Persons ID specified"));
}	
?>
<!-- end content -->

<?php
require("./include/footer.inc");
page_close();
?>
