<?php

function mysql_die($db) {
    global $t,$be;
    $be->box_full($t->translate("Database Access failed"), $db->Errno." : ".$db->Error);
}

function mktimestamp($time) {
    $timestamp = mktime(substr($time,8,2),substr($time,10,2),substr($time,12,2),substr($time,4,2),substr($time,6,2),substr($time,0,4));
    return $timestamp;
}


function timestr($timestamp) {
    $time = strftime("%A, %e. %B %Y, %H:%M:%S %Z", $timestamp);
    return $time;
}

function timestr_short($timestamp){
    $time = strftime("%e. %b, %H:%M", $timestamp);
    return $time;
}

function inssec($string) {
    global $PHP_SELF, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Insert a Category"));
	$bx->box_body_begin();
    echo "<table border=0 align=center cellspacing=0 cellpadding=3 width=100%>\n";
    echo "<form action=\"inscat.php\" method=\"POST\">\n";

    if ($string == "yes") {
		// Inserting Sections and/or Categories
      echo "<tr><td align=right>".$t->translate("Section").":</td><td><b>".$GLOBALS["section"]."</b></td></tr>\n";
      echo "<input type=\"hidden\" name=\"section\" value=\"".$GLOBALS["section"]."\">\n";

    } else {
      echo "<tr><td align=right>".$t->translate("Section").":</td><td>\n";
      echo "<select name=\"section\">\n";
      sec($GLOBALS["section"]);     // We select the first one to avoid having a blank line
      echo "</select></td></tr>\n";
    }

    echo "<tr><td align=right>".$t->translate("Category")." (64):</td><td><input type=\"TEXT\" name=\"category\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Insert")."\"></td></tr>\n";
    echo "</form>\n";
    echo "</td></tr>\n";
    echo "</table>\n";
	$bx->box_body_end();
	$bx->box_end();
}

// 
//  select_form($table, $param, $sel)
//  Displays the different parameter values of a table as a select form
// 

function select_form($table,$param,$sel) {
    $dbsel = new DB_SourceContact;
    if (!$dbsel->query("SELECT DISTINCT $param FROM $table ORDER BY $param ASC"))
    {
        mysql_die($dbsel);
    } else {
		$ret = "";
        while ($dbsel->next_record()) {
            $ret .= "<option";
            if ($dbsel->f($param) == $sel) {
                $ret .= " selected";
            }
            $ret .= ">".$dbsel->f($param)."\n";
        }
    }
    return $ret;
}

// 
//  select_cat($type)
//  Displays the different categories as a select form
// 

function select_cat($type,$sel) {
    $dbcat = new DB_SourceContact;
    $columns = "*";
    $tables = "categories";
    $where = "type='$type'";
    $order = "category ASC";
    if (!$dbcat->query("SELECT DISTINCT $columns FROM $tables WHERE $where ORDER BY $order"))
    {
        mysql_die($dbcat);
    } else {
        while ($dbcat->next_record()) {
            echo "<option";
            if ($dbcat->f("category") == $sel) {
                echo " selected";
            }
            echo ">".$dbcat->f("category")."\n";
        }
    }
}

// 
//  select_mcat($type)
//  Displays the different categories as a select form
// 

function select_mcat($type,$conid) {
    $dbcat = new DB_SourceContact;
    $dbcla = new DB_SourceContact;
    $columns = "*";
    $tables = "categories";
    $where = "type='$type'";
    $order = "category ASC";
    if (!$dbcat->query("SELECT DISTINCT $columns FROM $tables WHERE $where ORDER BY $order"))
    {
        mysql_die($dbcat);
    } else {
	    $columns = "class";
    	$tables = "classifications";
    	$where = "conid='$conid' AND type = '$type'";
    	if ($dbcla->query("SELECT $columns FROM $tables WHERE $where")) {
			$dbcla->next_record();
			$sel = $dbcla->f("class");
		} else {
			$sel = "";
		}
        while ($dbcat->next_record()) {
            echo "<option";
            if (ereg($dbcat->f("category"), $sel)) {
                echo " selected";
            }
            echo ">".$dbcat->f("category")."\n";
        }
    }
}

function wrap($string,$width=75,$break=" ") {
	$out = "";
	$lin = "";
	$tok = strtok($string,$break);
	while ($tok) {
		if ((strlen($lin) + strlen($tok)) > $width) {
			$out .= $lin."\n";
			$lin = "";
		}
		if (strlen($lin) > 0)
			$lin .= " ";
		$lin .= $tok;
		$tok = strtok (" ");
	}
	$out .= $lin;
	return $out;
}

function admin($db) {
	global $auth, $perm;
	$admin = 0;
	if (isset($auth) && !empty($auth->auth["perm"]) && ($perm->have_perm("admin") || $db->f("user") == $auth->auth["uname"])) {
		$admin = 1;
	}
	return $admin;
}

function nlmsg($period) {
  global $db;

  switch ($period) {
    case "weekly":
      $lastday = time() - 7 * 24 * 60 * 60;
      $where = "DATE_FORMAT(contact.modification,'%Y-%m-%d')<=\"".date("Y-m-d")."\" AND DATE_FORMAT(contact.modification,'%Y-%m-%d')>\"".date("Y-m-d",$lastday)."\"";
      break;
    case "daily":
    default:
      $where = "DATE_FORMAT(contact.modification,'%Y-%m-%d')=\"".date("Y-m-d")."\"";
      break;
  }

  $db->query("SELECT * FROM contact WHERE $where AND contact.status='A' ORDER BY contact.modification DESC"); 

  if ($db->num_rows() <= 0) return 0;

  $msg = $GLOBALS["sys_name"]." $period newsletter for ".date("l, dS of F Y, H:i:s T")."\n";
  $msg .= "Number of news: ".$db->num_rows()."\n";
  $msg .= "\n               ---------------------------------\n";
  $msg .= "                   Contact News Headlines\n";
  $msg .= "               ---------------------------------\n\n";
	
  $i = 1;
  while($db->next_record()) {
    $msg .= "$i: ".$db->f("name")."\n";
    $i++;
  }

  $msg .= "\n               ---------------------------------\n";
  $msg .= "                   Contact News Details\n";
  $msg .= "               ---------------------------------\n";

  $db->seek(0);

  $i = 1;
  while ($db->next_record()) {
    $timestamp = mktimestamp($db->f("modification"));
    $msg .= "\nContact      : $i\n";
    $msg .= "Name         : ".$db->f("name")."\n";
    $msg .= "Date         : ".date("l, dS of F Y, H:i:s T", $timestamp)."\n";
    $msg .= "Kategorie    : ".$db->f("category")."\n";
    if ($db->f("homepage") != "") {
    	$msg .= "Homepage     : ".$db->f("homepage")."\n";
	}
    $msg .= $GLOBALS["sys_name"].": ".$GLOBALS["sys_url"]."conbyconid.php?id=".$db->f("conid")."\n";
    $msg .= "\n               ---------------------------------\n";
    $i++;
  }
  $msg .= "\nYou get this ".$GLOBALS["sys_name"]." $period newsletter,"
  ."\nbecause you have subscribed to the mailing list ";

  switch ($period) {
    case "weekly":
      $msg .= "\n".$GLOBALS["ml_weeklynewstoaddr"]."."
      ."\nTo unsubscribe from this mailing list,"
      ."\nsend a message by email to"
      ."\n".$GLOBALS["ml_weeklynewsreqaddr"]
      ."\nwith \"unsubscribe <password>\" as subject or visit"
      ."\n".$GLOBALS["ml_weeklylisturl"];
      break;
    case "daily":
    default:
      $msg .= "\n".$GLOBALS["ml_newstoaddr"]."."
      ."\nTo unsubscribe from this mailing list,"
      ."\nsend a message by email to"
      ."\n".$GLOBALS["ml_newsreqaddr"]
      ."\nwith \"unsubscribe <password>\" as subject or visit"
      ."\n".$GLOBALS["ml_listurl"];
      break;
  }
  $msg .= "\nand follow the instructions there."
  ."\n\n - The ".$GLOBALS["sys_name"]." crew";

  return $msg;
}

function mailuser($perms, $subj, $message) {
  global $t, $db;
  $db->query("SELECT email_usr FROM auth_user WHERE perms LIKE '%$perms%'");
  while($db->next_record()) {
    mail($db->f("email_usr"),"[".$GLOBALS["sys_name"]."] ".$subj,$message,"From: ".$GLOBALS["ml_fromaddr"]."\nReply-To: ".$GLOBALS["ml_replyaddr"]."\nX-Mailer: PHP");
  }
}

?>
