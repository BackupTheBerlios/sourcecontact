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
# Adding person of a contact
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
require("./include/perlib.inc");

$bx = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php
if ($perm->have_perm("user_pending")) {
  $be->box_full($t->translate("Error"), $t->translate("Access denied"));
  $auth->logout();
} else {
  if (isset($id)) {

	// Look if contact is already in table
    $columns = "*";
    $tables = "contact";
    $where = "conid='$id'";
    if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
      mysql_die($db);
    } else {

	  // If contact in table ask for person
      if ($db->next_record()) {
        if ($db->f("user") == $auth->auth["uname"] || $perm->have_perm("admin")) {
          perform($db);
        } else {
          $be->box_full($t->translate("Error"), $t->translate("Access denied"));
		}

	  // If contact is not in table
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
