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
# Add classification of an user contact
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
require("./include/clalib.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {

  // If contact id specified
  if (isset($id)) {

	// Look if contact is already in table
    $columns = "*";
    $tables = "contact";
    $where = "conid='$id'";
    if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
      mysql_die($db);
    } else {

	  // If contact in table
      if ($db->next_record()) {

        // If contact owner is logged in user
        if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {

	      // Look if clasifications are already in table
          $dbcla = new DB_SourceContact;
          $columns = "*";
          $tables = "classifications,contact";
          $where = "classifications.conid='$id' AND classifications.type = '$type' AND contact.conid = classifications.conid";
          if ($dbcla->query("SELECT $columns FROM $tables WHERE $where")) {

	        // If classifications are in table
            if ($dbcla->next_record()) {

              // Modify existing classifications
              clamod($dbcla);
            } else {

              // Insert new classifications
              claform($db);
            }
          } else {
            mysql_die($db);
          }

        } else {
          $be->box_full($t->translate("Error"), $t->translate("Access denied").".");
        }

	  // If contact not in table
      } else {
        $be->box_full($t->translate("Error"), $t->translate("Contact")." (ID: $id) ".$t->translate("does not exist").".");
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
