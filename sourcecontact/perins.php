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
# Insert contact person of a contact
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
<?php
if ($perm->have_perm("user_pending")) {
	$be->box_full($t->translate("Error"), $t->translate("Access denied"));
	$auth->logout();
} else {
	if (isset($id)) {
	$salutation_per = trim($salutation_per);
	$firstname_per = trim($firstname_per);
	$lastname_per = trim($lastname_per);
	$grad_per = trim($grad_per);
	$phone_per = trim($phone_per);
	$fax_per = trim($fax_per);
	$email_per = trim($email_per);
	$homepage_per = trim($homepage_per);
	if (!empty($homepage_per) && !ereg("^http://", $homepage_per)) {
		$homepage_per = "http://".$homepage_per;
	}
	$comment_per = trim($comment_per);
	if (!empty($lastname_per)) {

		// Look if contact is in table
    	$columns = "*";
    	$tables = "contact";
    	$where = "conid='$id'";
    	if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
      		mysql_die($db);
    	} else {

			// If contact in table
			if ($db->next_record()) {
				if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {
					// Insert new contact person
					$tables = "persons";
    				$set = "conid_per='$id',salutation_per='$salutation_per',firstname_per='$firstname_per',lastname_per='$lastname_per',grad_per='$grad_per',position_per='$position_per',phone_per='$phone_per',fax_per='$fax_per',email_per='$email_per',homepage_per='$homepage_per',comment_per='$comment_per',status_per='A',modification_per=NOW(),creation_per=NOW()";
					if (!$db->query("INSERT $tables SET $set")) {
						mysql_die($db);
					}

					// Select and show new/updated contact with contact persons
					conbyconid($db,$id);
					perbyconid($db,$id);
					if ($ml_notify) {
						$msg = "insert contact person \"$firstname_per $lastname_per\" of contact (ID: $id) by ".$auth->auth["uname"].".";
						mailuser("admin", "insert contact person", $msg);
					}
        		} else {
          			$be->box_full($t->translate("Error"), $t->translate("Access denied"));
				}

			// If contact is not in table
			} else {
				$be->box_full($t->translate("Error"), $t->translate("Contact")." (ID: $id) ".$t->translate("does not exist").".");
      		}
		}
	} else {
		$be->box_full($t->translate("Error"), $t->translate("No Lastname specified"));
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
