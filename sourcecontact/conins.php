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
# Inserts a contact
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
	$status = 'A';

	$name = trim($name);
	$address = trim($address);
	$country = trim($country);
	$state = trim($state);
	$city = trim($city);
	$zip = trim($zip);
	$phone = trim($phone);
	$fax = trim($fax);
	$email = trim($email);
	$comment = trim($comment);
	$homepage = trim($homepage);
	if (!empty($homepage) && !ereg("^http://", $homepage)) {
		$homepage = "http://".$homepage;
	}
	if (!empty($name)) {
		$tables = "contact";
		$columns = "*";
		$where = "name='$name'";
		if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
			mysql_die($db);
		} else {

			// If contact already exists
			if ($db->num_rows() > 0) {
				$be->box_full($t->translate("Error"), $t->translate("Contact")." $name ".$t->translate("already exists"));

			// If a new contact
			} else {
        		$set = "name='$name',address='$address',country='$country',state='$state',city='$city',zip='$zip',phone='$phone',fax='$fax',email='$email',homepage='$homepage',comment='$comment',category='$category',status='$status',user='".$auth->auth["uname"]."',modification=NOW(),creation=NOW()";
        		if (!$db->query("INSERT $tables SET $set")) {
					mysql_die($db);
        		} else {

					// Select and show new contact
					conbyname($db,$name);
					if ($ml_notify) {
						$msg = "insert contact \"$name\" by ".$auth->auth["uname"].".";
						mailuser("admin", "insert contact", $msg);
					}
				}
			}
		}
	} else {
		$be->box_full($t->translate("Error"), $t->translate("No Name specified"));
	}
}
?>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
