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
# Shows the recent contact persons
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

require("./include/header.inc");
require("./include/conlib.inc");
require("./include/clalib.inc");
require("./include/perlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<table BORDER=0 CELLSPACING=10 CELLPADDING=0 WIDTH=100% >
<tr width=80% valign=top><td>
<?php
if (!isset($cnt)) $cnt = 0;
$prev_cnt = $cnt + $config_showfull_perperpage;
if ($cnt >= $config_showfull_perperpage) $next_cnt = $cnt - $config_showfull_perperpage;
else $next_cnt = 0;

$query = perquery(0);
$db->query($query);
persort($db,0);
if ($db->num_rows() > 0) {
	while ($db->next_record()) {
		pershow($db,admin($db));
	}
	pernav($db,0);
} else {
	$be->box_full($t->translate("Attention!"), $t->translate("No more Contact Person exist").".");
}
?>
</td><td width=20%>
<?php

// Recent Contact Persons at the right column
peridx($config_showshort_perperpage);

?>
</td></tr>
</table>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
