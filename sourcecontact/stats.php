<?php

######################################################################
# SourceContact: Open Source Contact Management
# =============================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de) and
#                Gregorio Robles (grex@scouts-es.org)
#
# BerliOS SourceContact: http://sourcecontact.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# Statistics of the System
# some code (or some idea) has been taken from PHP-Nuke (http://php-nuke.org)
# which also lies under the GPL
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
require("./include/statslib.inc");

$bx = new box("95%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_body_font_color,$th_box_body_align);
$be = new box("80%",$th_box_frame_color,$th_box_frame_width,$th_box_title_bgcolor,$th_box_title_font_color,$th_box_title_align,$th_box_body_bgcolor,$th_box_error_font_color,$th_box_body_align);
?>

<!-- content -->
<?php

// $iter is a variable for printing the Top Statistics in steps of 10 apps
if (!isset($iter)) $iter=0;
$iter*=10;

$bx->box_begin();
$bx->box_title($t->translate("$sys_name Statistics"));
$bx->box_body_begin();

echo "<table border=0 width=100% cellspacing=0>\n";
echo "<tr>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=general")."\">".$t->translate("General $sys_name Statistics")."</a></center></td>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=city")."\">".$t->translate("Contacts by Cities")."</a></center></td>\n";
echo "</tr>\n";

echo "<tr>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=email")."\">".$t->translate("Contacts by Email Domains")."</a></center></td>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=type")."\">".$t->translate("Contacts by Contact Categories")."</a></center></td>\n";
echo "</tr>\n";

echo "<tr>\n";
echo "<tr><td><center><a href=\"".$sess->url("stats.php?option=country")."\">".$t->translate("Contacts by Countries")."</a></center></td>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=categories")."\">".$t->translate("Contacts by Categories")."</a></center></td>\n";
echo "</tr>\n";

echo "<tr>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=state")."\">".$t->translate("Contacts by States")."</a></center></td>\n";
echo "<td><center><a href=\"".$sess->url("stats.php?option=classifications")."\">".$t->translate("Contacts by Classifications")."</a></center></td>\n";
echo "</tr>\n";

echo "</table>\n";

$bx->box_body_end();
$bx->box_end();

if (isset($option)) {
// We need to know the total number of contacts for certain stats

  $db->query("SELECT COUNT(*) FROM contact");
  $db->next_record();
  $total_number_cons = $db->f("COUNT(*)");
  $numiter = ($db->f("COUNT(*)")/10);

  switch($option) {

// General stats
    case "general":

      $bx->box_begin();
      $bx->box_title($t->translate("General $sys_name Statistics"));
      $bx->box_body_begin();

      echo "<CENTER><table border=0 width=90% align=center cellspacing=0>\n";

    // Total number of contacts
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Contacts")."</td>\n";
      echo "<td width=20% align=right>".$total_number_cons."</td></tr>\n";

    // Number of inserted or modified Contacts during the last week
      $day=7;
      $db->query("SELECT COUNT(*) FROM contact WHERE DATE_FORMAT(contact.modification,'%Y-%m-%d')>=DATE_SUB(CURRENT_DATE,INTERVAL \"$day\" DAY) AND contact.status='A'");
      $db->next_record();
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Insertions and Modifications during last week")."</td>\n";
      echo "<td width=20% align=right>".$db->f("COUNT(*)")."</td></tr>\n";

    // Number of inserted or modified Contacts today
      $day=1;
      $db->query("SELECT COUNT(*) FROM contact WHERE DATE_FORMAT(contact.modification,'%Y-%m-%d')>=DATE_SUB(CURRENT_DATE,INTERVAL \"$day\" DAY) AND contact.status='A'");
      $db->next_record();
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Insertions and Modifications during last day")."</td>\n";
      echo "<td width=20% align=right>".$db->f("COUNT(*)")."</td></tr>\n";

    // Total number of Contact Persons
      echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
      $db->query("SELECT COUNT(*) FROM persons");
      $db->next_record();
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Contact Persons")."</td>\n";
      echo "<td width=20% align=right>".$db->f("COUNT(*)")."</td></tr>\n";

    // Number of inserted or modified Contact Persons during the last week
      $day=7;
      $db->query("SELECT COUNT(*) FROM persons WHERE DATE_FORMAT(persons.modification_per,'%Y-%m-%d')>=DATE_SUB(CURRENT_DATE,INTERVAL \"$day\" DAY) AND persons.status_per='A'");
      $db->next_record();
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Insertions and Modifications during last week")."</td>\n";
      echo "<td width=20% align=right>".$db->f("COUNT(*)")."</td></tr>\n";

    // Number of inserted or modified Contact Persons today
      $day=1;
      $db->query("SELECT COUNT(*) FROM persons WHERE DATE_FORMAT(persons.modification_per,'%Y-%m-%d')>=DATE_SUB(CURRENT_DATE,INTERVAL \"$day\" DAY) AND persons.status_per='A'");
      $db->next_record();
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of Insertions and Modifications during last day")."</td>\n";
      echo "<td width=20% align=right>".$db->f("COUNT(*)")."</td></tr>\n";

    // Number of authorised users
      echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
      $db->query("SELECT COUNT(*) FROM auth_user");
      $db->next_record();
      echo "<tr><td width=85%>&nbsp;".$t->translate("Number of registered Users")."</td>\n";
      echo "<td width=20% align=right>".$db->f("COUNT(*)")."</td></tr>\n";

     // SourceContact Version
      echo "<tr><td>&nbsp;</td><td>&nbsp;</td></tr>\n";
      echo "<tr><td width=85%>&nbsp;".$t->translate("$sys_name Version")."</td>\n";
      echo "<td width=20% align=right>".$SourceContact_Version."</td></tr>\n";

      echo "</td></tr>\n";
      echo "</table></CENTER>\n";
      $bx->box_body_end();
      $bx->box_end();

      break;

// Contacts by Email Domains
    case "email":

    // Total number of contacts
      $url = "0"; 		// No URL in function stats_display
      $urlquery = "0";		// No URL query in function stats_display

      stats_title($t->translate("Contacts listed by Email Domain"));
      for($i=1;$i<sizeof($domain_country);$i++) {
        $num = 0;
        $like = "'%.".$domain_country[$i][0]."'";
        $db->query("Select COUNT(*) from contact WHERE email LIKE $like");
        $db->next_record();
        $num = $db->f("COUNT(*)");
        if (100 * $num/$total_number_cons > $MinimumAppsByEmail) stats_display($domain_country[$i][1],$num,$url,$urlquery,$total_number_cons); 
      }
      stats_end();
      break;

// Country
    case "country":

     stats_title($t->translate("Contacts listed by Countries"));
     $db->query("SELECT contact.country, COUNT(*) AS cnt FROM contact GROUP BY contact.country ORDER BY cnt DESC");
     while($db->next_record()) {
       $url = "index.php";
       $urlquery = array("by" => "filter", "country" => $db->f("country"));
       stats_display($db->f("country"),$db->f("cnt"),$url,$urlquery,$total_number_cons);
     }
     stats_end();
     break;

// State
    case "state":

     stats_title($t->translate("Contacts listed by States"));
     $db->query("SELECT contact.state, COUNT(*) AS cnt FROM contact GROUP BY contact.state ORDER BY cnt DESC");
     while($db->next_record()) {
       $url = "index.php";
       $urlquery = array("by" => "filter", "state" => $db->f("state"));
       stats_display($db->f("state"),$db->f("cnt"),$url,$urlquery,$total_number_cons);
     }
     stats_end();
     break;

// City
    case "city":

     stats_title($t->translate("Contacts listed by Cities"));
     $db->query("SELECT contact.city, COUNT(*) AS cnt FROM contact GROUP BY contact.city ORDER BY cnt DESC");
     while($db->next_record()) {
       $url = "index.php";
       $urlquery = array("by" => "filter", "city" => $db->f("city"));
       stats_display($db->f("city"),$db->f("cnt"),$url,$urlquery,$total_number_cons);
     }
     stats_end();
     break;

// Contact Categories
    case "type":

     stats_title($t->translate("Contacts listed by Contact Categories"));
     $db->query("SELECT contact.category, COUNT(*) AS cnt FROM contact GROUP BY contact.category ORDER BY cnt DESC");
     while($db->next_record()) {
       $url = "index.php";
       $urlquery = array("by" => "filter", "category" => $db->f("category"));
       stats_display($db->f("category"),$db->f("cnt"),$url,$urlquery,$total_number_cons);
     }
     stats_end();
     break;

// Categories
    case "categories":

      stats_title($t->translate("Contacts listed by Categories"));
      $db->query("SELECT DISTINCT type, COUNT(*) AS cnt FROM categories GROUP BY type");
      while($db->next_record()) {
        $type = $db->f("type");
        if ($db->f("cnt") > 0 && $type != "Contact") {
          stats_subtitle($t->translate("Contact Category")." ".$type);
          $dbtot = new DB_SourceContact;
		  $dbtot->query("SELECT COUNT(*) FROM contact WHERE category='$type'");
  		  $dbtot->next_record();
		  $total_number_cat = $dbtot->f("COUNT(*)");
          $db1 = new DB_SourceContact;
          $db1->query("SELECT DISTINCT category,COUNT(*) AS cnt1 FROM categories WHERE type='$type' GROUP BY category");
          while ($db1->next_record()) {
	        $category = $db1->f("category");
          	$db2 = new DB_SourceContact;
          	$db2->query("SELECT COUNT(*) AS cnt2 FROM classifications WHERE class LIKE '%$category%'");
          	if ($db2->next_record()) {
	        	$cnt2 = $db2->f("cnt2");
            	if ($cnt2 > 0) { 
              		$url = "index.php";
	          		$urlquery = array("by" => "filter", "class" => $category);
              		stats_display($db1->f("category"),$cnt2,$url,$urlquery,$total_number_cat);
            	}
			}
          }
        }
      }
      stats_end();
      break;

// Classifications
    case "classifications":

      stats_title($t->translate("Contacts listed by Classifications"));
      $db->query("SELECT DISTINCT type, COUNT(*) AS cnt FROM categories GROUP BY type");
      while($db->next_record()) {
        $type = $db->f("type");
        if ($db->f("cnt") > 0 && $type != "Contact") {
          stats_subtitle($t->translate("Contact Category")." ".$type);
          $dbtot = new DB_SourceContact;
		  $dbtot->query("SELECT COUNT(*) FROM contact WHERE category='$type'");
  		  $dbtot->next_record();
		  $total_number_cat = $dbtot->f("COUNT(*)");
          $db2 = new DB_SourceContact;
          $db2->query("SELECT class, COUNT(*) AS cnt2 FROM classifications WHERE type='$type' GROUP BY class");
          while ($db2->next_record()) {
	        $cnt2 = $db2->f("cnt2");
            if ($cnt2 > 0) { 
              $url = "index.php";
	          $urlquery = array("by" => "filter", "class" => $db2->f("class"));
              stats_display($db2->f("class"),$cnt2,$url,$urlquery,$total_number_cat);
            }
          }
        }
      }
      stats_end();
      break;

  }
}

?>
<!-- end content -->

<?php
require("./include/footer.inc");
page_close();
?>
