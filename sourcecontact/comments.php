<?php

######################################################################
# SourceBiz: Open Source Business
# ===============================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de)
#
# BerliOS SourceBiz: http://sourcebiz.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This shows the recent comments
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################  

require("./include/prepend.php3");

page_open(array("sess" => "SourceBiz_Session"));
if (isset($auth) && !empty($auth->auth["perm"])) {
  page_close();
  page_open(array("sess" => "SourceBiz_Session",
                  "auth" => "SourceBiz_Auth",
                  "perm" => "SourceBiz_Perm"));
}

require("./include/header.inc");
require("./include/cmtlib.inc");

$bx = new box("100%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
$bs = new box("100%",$th_strip_frame_color,$th_strip_frame_width,$th_strip_title_bgcolor,$th_strip_title_font_color,$th_strip_title_align,$th_strip_body_bgcolor,$th_strip_body_font_color,$th_strip_body_align);
?>

<!-- content -->
<table BORDER=0 CELLSPACING=10 CELLPADDING=0 WIDTH="100%" >
<tr width=80% valign=top><td>
<?php

if (!isset($cnt)) $cnt = 0;
$prev_cnt = $cnt + $config_showfull_cmtperpage;
if ($cnt >= $config_showfull_cmtperpage) $next_cnt = $cnt - $config_showfull_cmtperpage;
else $next_cnt = 0;

$query = cmtquery(0);
$db->query($query);
cmtsort($db,0);
if ($db->num_rows() > 0) {
  while ($db->next_record()) {
    cmtshow($db,admin($db));
  }
  cmtnav($db,0);
} else {
  $be->box_full($t->translate("Attention!"), $t->translate("No more Comment exist").".");
}
?>
</td><td width=20%>
<?php

// Recent News at the right column

cmtidx($config_showshort_entperpage);

?>
</td></tr>
</table>
<!-- end content -->

<?php
require("./include/footer.inc");
@page_close();
?>
