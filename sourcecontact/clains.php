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
# Insert classification of an user contact
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

  // If contact id specified
  if (isset($id)) {
  if (!empty($classes)) {

	// Look if contact is in table
    $columns = "*";
    $tables = "contact";
    $where = "conid='$id'";
    if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
      mysql_die($db);
    } else {

	  // If contact in table
      if ($db->next_record()) {

        // If contact owner is a logged in user
        if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {

	      // Insert new class
          $clalist = addslashes(implode($classes,","));
          $tables = "classifications";
          $set = "conid='$id',type='$type',class='$clalist'";
          if (!$db->query("INSERT $tables SET $set")) {
            mysql_die($db);
          }

	      // Select and show new/updated contact with classification
          conbyconid($db,$id);
		  if ($ml_notify) {
		    $msg = "insert classification \"$clalist\" of contact (ID: $id) by ".$auth->auth["uname"].".";
		    mailuser("admin", "insert classification", $msg);
		  }

        // If contact owner isn't a logged in user
        } else {
          $be->box_full($t->translate("Error"), $t->translate("Access denied"));
        }

	  // If contact not in table
      } else {
        $be->box_full($t->translate("Error"), $t->translate("Contact")." (ID: $id) ".$t->translate("does not exist"));
      }
    }
  } else {
    $be->box_full($t->translate("Error"), $t->translate("No Classifications specified"));
  }

  // If contact id not specified
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
