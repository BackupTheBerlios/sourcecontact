<?php

function perform($db) {
    global $sess, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Contact Person")." ".$t->translate("of")." \"".$db->f("name")."\"");
	$bx->box_body_begin();
    echo "<form action=\"".$sess->url("perins.php")."\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right>".$t->translate("Salutation").":</td>\n";
    echo "<td><select name=\"salutation_per\">\n";
    echo "<option value=\"Mr.\">".$t->translate("Mr.")."\n";
    echo "<option value=\"Mrs.\">".$t->translate("Mrs.")."\n";
    echo "</select></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Last name")." (64):</td><td><input type=\"TEXT\" name=\"lastname_per\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("First name")." (64):</td><td><input type=\"TEXT\" name=\"firstname_per\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Grad")." (64):</td><td><input type=\"TEXT\" name=\"grad_per\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Position")." (64):</td><td><input type=\"TEXT\" name=\"position_per\" size=40 maxlength=64></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Phone")." (128):</td><td><input type=\"TEXT\" name=\"phone_per\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Fax")." (128):</td><td><input type=\"TEXT\" name=\"fax_per\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Email")." (255):</td><td><input type=\"TEXT\" name=\"email_per\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Homepage")." (255):</td><td><input type=\"TEXT\" name=\"homepage_per\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Comment")." (255):</td><td><input type=\"TEXT\" name=\"comment_per\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Go")."\"></td>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("conid")."\">\n";
    echo "</form>\n";
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function pershow($db,$admin) {
    global $sess, $t, $bx;
	$bx->box_begin();
	$bx->box_title($t->translate("Contact Person"));
	$bx->box_body_begin();
	if ($admin || $db->f("status_per") == 'A') {
	    echo "<table border=0 cellspacing=1 cellpadding=3 bgcolor=".$GLOBALS["th_box_body_bgcolor"].">\n";
		$salutation_per = $db->f("salutation_per");
		if (!empty($salutation_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Salutation").":</b></td><td>".$t->translate($db->f("salutation_per"))."</td></tr>\n";
    	}
		$lastname_per = $db->f("lastname_per");
		if (!empty($lastname_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Last name").":</b></td><td>".$db->f("lastname_per")."</td></tr>\n";
    	}
		$firstname_per = $db->f("firstname_per");
		if (!empty($firstname_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("First name").":</b></td><td>".$db->f("firstname_per")."</td></tr>\n";
		}
		$grad_per = $db->f("grad_per");
		if (!empty($grad_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Grad").":</b></td><td>".$db->f("grad_per")."</td></tr>\n";
    	}
		$position_per = $db->f("position_per");
		if (!empty($position_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Position").":</b></td><td>".$db->f("position_per")."</td></tr>\n";
    	}
		$phone_per = $db->f("phone_per");
		if (!empty($phone_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Phone").":</b></td><td>".$db->f("phone_per")."</td></tr>\n";
    	}
		$fax_per = $db->f("fax_per");
		if (!empty($fax_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Fax").":</b></td><td>".$db->f("fax_per")."</td></tr>\n";
    	}
		$email_per = $db->f("email_per");
		if (!empty($email_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Email").":</b></td><td>&lt;<a href=\"mailto:".$db->f("email_per")."\">".ereg_replace("@"," at ",htmlentities($db->f("email_per")))."</a>&gt;</td></tr>\n";
		}
		$homepage_per = $db->f("homepage_per");
		if (!empty($homepage_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Homepage").":</b></td><td>&lt;<a href=\"".$db->f("homepage_per")."\" target=_blank>".$db->f("homepage_per")."</a>&gt;</td></tr>\n";
		}
		$comment_per = $db->f("comment_per");
		if (!empty($comment_per)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Comment").":</b></td><td>".$db->f("comment_per")."</td></tr>\n";
    	}
	    echo "</table>\n";
	}
    echo "<p class=\"small\"><b>".$t->translate("of")."</b> <a href=\"".$sess->url("conbyconid.php").$sess->add_query(array("id" => $db->f("conid")))."\">".$db->f("name")."</a>\n";
    $timestamp = mktimestamp($db->f("modification_per"));
    echo "<br><b>".timestr($timestamp)."</b>\n";
	$bx->box_body_end();
	if ($admin || $db->f("status") == 'D') {
		$bx->box_title_begin();
		if ($db->f("status_per") == 'D') {
			if ($admin) {
			    echo "<a href=\"".$sess->url("perupd.php").$sess->add_query(array("id" => $db->f("perid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update Contact Person")."\"></a>\n";
				echo "&nbsp;&nbsp;";
				echo "<a href=\"".$sess->url("perupd.php").$sess->add_query(array("id" => $db->f("perid")))."\">";
			}
			echo "<img src=\"images/editdelete.png\" border=0 alt=\"";
			if ($admin) {
				echo $t->translate("Undelete")."\"></a>\n";
			} else {
				echo $t->translate("Deleted")."\">\n";
			}
		} else {
			if ($admin) {
		    	echo "<a href=\"".$sess->url("perupd.php").$sess->add_query(array("id" => $db->f("perid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update Contact Person")."\"></a>\n";
			}
		}
		$bx->box_title_end();
	}
	$bx->box_end();
}

function permod($db) {
   global $sess, $perm, $t, $bx;
	$bx->box_begin();
	$bx->box_title($t->translate("Contact Person")." ".$t->translate("of")." \"".$db->f("name")."\"");
	$bx->box_body_begin();
    echo "<form action=\"".$sess->self_url()."\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right>".$t->translate("Salutation").":</td>\n";
    echo "<td><select name=\"salutation_per\">\n";
	$salutation = $db->f("salutation_per");
    echo "<option value=\"Mr.\"";
	if ($salutation == "Mr.") echo " selected";
	echo ">".$t->translate("Mr.")."\n";
    echo "<option value=\"Mrs.\"";
	if ($salutation == "Mrs.") echo " selected";
	echo ">".$t->translate("Mrs.")."\n";
    echo "</select></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Last name")." (64):</td><td><input type=\"TEXT\" name=\"lastname_per\" size=40 maxlength=64 value=\"".$db->f("lastname_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("First name")." (64):</td><td><input type=\"TEXT\" name=\"firstname_per\" size=40 maxlength=64 value=\"".$db->f("firstname_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Grad")." (64):</td><td><input type=\"TEXT\" name=\"grad_per\" size=40 maxlength=64 value=\"".$db->f("grad_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Position")." (64):</td><td><input type=\"TEXT\" name=\"position_per\" size=40 maxlength=64 value=\"".$db->f("position_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Phone")." (128):</td><td><input type=\"TEXT\" name=\"phone_per\" size=40 maxlength=128 value=\"".$db->f("phone_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Fax")." (128):</td><td><input type=\"TEXT\" name=\"fax_per\" size=40 maxlength=128 value=\"".$db->f("fax_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Email")." (255):</td><td><input type=\"TEXT\" name=\"email_per\" size=40 maxlength=255 value=\"".$db->f("email_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Homepage")." (255):</td><td><input type=\"TEXT\" name=\"homepage_per\" size=40 maxlength=255 value=\"".$db->f("homepage_per")."\">";
	$homepage_per = $db->f("homepage_per");
	if (!empty($homepage_per)) {
		echo "&nbsp;[<a href=\"".$db->f("homepage_per")."\" target=\"_blank\">".$t->translate("Check")."</a>]\n";
	}
	echo "</td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Comment")." (255):</td><td><input type=\"TEXT\" name=\"comment_per\" size=40 maxlength=255 value=\"".$db->f("comment_per")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Status")." :</td><td>";
	switch ($db->f("status_per")) {
	case 'A':
		echo $t->translate("active");
		break;
	case 'D':
		echo $t->translate("deleted");
		break;
	}
	echo "</td></tr>\n";
	echo "<tr><td align=right>".$t->translate("Action").":</td><td>\n";
	echo "<select name=\"action\">\n";
	echo "<option value=\"change\"";
	echo ">".$t->translate("Change")."\n";
	if ($db->f("status_per") == 'A') {
		echo "<option value=\"delete\"";
		echo ">".$t->translate("Delete")."\n";
	}
	if ($db->f("status_per") == 'D') {
		echo "<option value=\"undelete\"";
		echo ">".$t->translate("Undelete")."\n";
	}
	if ($perm->have_perm("admin")) {
		echo "<option value=\"erase\"";
		echo ">".$t->translate("Erase")."\n";
	}
	echo "</select></td></tr>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("perid")."\">\n";
    echo "<input type=\"hidden\" name=\"status_per\" value=\"".$db->f("status_per")."\">\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Go")."\"></td>\n";
    echo "</form>\n";
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function perbyconid($db,$conid) {
	global $t, $be, $auth, $perm;
	global $cnt,$prev_cnt,$next_cnt,$config_showfull_perperpage;

	if (!isset($cnt)) $cnt = 0;
	$prev_cnt = $cnt + $config_showfull_perperpage;
	if ($cnt >= $config_showfull_perperpage) $next_cnt = $cnt - $config_showfull_perperpage;
	else $next_cnt = 0;

	$query = perquery($conid);
	if (!$db->query($query)) {
		mysql_die($db);
	} else {
		if ($db->num_rows() > 0) {
			persort($db,$conid);
			while ($db->next_record()) {
				pershow($db,admin($db));
			}
			pernav($db,$conid);
		} else {
			$errmsg = $t->translate("Contact Person")." ".$t->translate("for Contact")." (ID: $conid) ".$t->translate("does not exist").".";
			$be->box_full($t->translate("Attention!"), $errmsg);
		}
	}
}


function perbyperid($db,$perid) {
	global $t, $be, $auth, $perm;
	$columns = "*";
	$tables = "persons,contact";
	$where = "persons.perid='$perid' AND contact.conid=persons.conid_per";
	$group = "persons.perid";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where GROUP BY $group")) {
		mysql_die($db);
	} else {
		if ($db->next_record()) {
			pershow($db,admin($db));
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Customer")." (ID: $perid) ".$t->translate("does not exist").".");
		}
	}
}


function peridx($num) {
	global $sess, $t, $db, $bx;
    $columns = "persons.*,contact.name";
    $tables = "persons,contact";
    $where = "persons.status_per='A' AND persons.conid_per = contact.conid";
    $order = "persons.modification_per DESC";
    $limit = "0,".$num;
    if (!$db->query("SELECT $columns FROM $tables WHERE $where ORDER BY $order LIMIT $limit"))
    {
        mysql_die($db);
    } else {
        if ($db->num_rows() > 0) {
			$bx->box_begin();
			$bx->box_title_begin();
            echo "<center><b>".$t->translate("Contact Persons")."</b></center></a>";
			$bx->box_title_end();
			$bx->box_body_begin();
            while($db->next_record()) {
                echo "<li class=\"small\"><a href=\"".$sess->url("perbyperid.php").$sess->add_query(array("id" => $db->f("perid")))."\">".$db->f("firstname_per")." ".$db->f("lastname_per")."</a> (".$db->f("name").")</li>\n";
            }
			$bx->box_body_end();
			$bx->box_end();
        }
    }
}


function perquery($conid) {
    global $by,$cnt,$name,$firstname,$lastname,$grad,$position,$comment;
    global $auth, $logout, $bs, $config_showfull_perperpage;
	$columns = "*";
	$tables = "persons,contact";
	$like = "";
	switch ($by) {
	case "name":
		$order = "ORDER BY persons.lastname_per ASC";
		break;
	case "filter":
		$order = "";
		if (isset($name) && !empty($name)) {
			$like .= "AND contact.name LIKE '%$name%'";
		}
		if (isset($firstname) && !empty($firstname)) {
			$like .= "AND persons.firstname_per LIKE '%$firstname%'";
		}
		if (isset($lastname) && !empty($lastname)) {
			$like .= "AND persons.lastname_per LIKE '%$lastname%'";
		}
		if (isset($grad) && !empty($grad)) {
			$like .= "AND persons.grad_per LIKE '%$grad%'";
		}
		if (isset($position) && !empty($position)) {
			$like .= "AND persons.position_per LIKE '%$position%'";
		}
		if (isset($comment) && !empty($comment)) {
			$like .= "AND persons.comment_per LIKE '%$comment%'";
		}
		break;			
	case "date":
	default:
		$order = "ORDER BY persons.modification_per DESC";
		break;
	}
	$where = "contact.conid = persons.conid_per $like";
	if (!isset($auth) || empty($auth->auth["perm"]) || $logout) {
		$where .= " AND persons.status_per='A'";
	}
	if ($conid > 0) {
		$where = "persons.conid_per='$conid' AND ".$where;
	}
	$limit = $cnt.",".$config_showfull_perperpage;
	return "SELECT $columns FROM $tables WHERE $where $order LIMIT $limit";
}


function persort($db,$conid) {
	global $PHP_SELF,$sess,$t,$bs,$config_showfull_conperpage;
    global $by,$cnt,$prev_cnt,$next_cnt,$name,$firstname,$lastname,$grad,$position,$comment;
	if ($conid > 0) {
		$ref = "perbyconid.php";
	} else {
		$ref = basename($PHP_SELF);
	}
	$sort = $t->translate("Contact Persons")." ".$t->translate("sorted by").": ";
	if (!empty($by) && $by != "date") {
		$sort .= "<a href=\"".$sess->url($ref);
		if ($conid > 0) {
			$darray["id"] = $conid;
		}
		$darray["by"] = "date";
		$sort .= $sess->add_query($darray)."\">".$t->translate("Date")."</a>";
	} else {
		$sort .= $t->translate("Date");
	}
	$sort .= " | ";
	if ($by != "name") {
		$sort .= "<a href=\"".$sess->url($ref);
		if ($conid > 0) {
			$narray["id"] = $conid;
		}
		$narray["by"] = "name";
		$sort .= $sess->add_query($narray)."\">".$t->translate("Name")."</a>";
	} else {
		$sort .= "".$t->translate("Name");
	}
	$sort .= " | ";
	if ($by != "filter") {
		$sort .= "<a href=\"".$sess->url($ref);
		if ($conid > 0) {
			$farray["id"] = $conid;
		}
		$farray["by"] = "filter";
		$sort .= $sess->add_query($farray)."\">".$t->translate("Filter")."</a>\n";
	} else {
		$sort .= $t->translate("Filter")."\n";
	}
	$bs->box_strip($sort);

	if ($by == "filter") {
		$filter = "<table border=0 align=center cellspacing=0 cellpadding=3><tr>\n"
		."<form action=\"".$sess->url($ref)."\" method=\"POST\">\n"
		."<td><b>".$t->translate("Filter").":</b></td>\n";
		if ($conid <= 0) {
			$filter .= "<td><b>".$t->translate("Contact")."</b></td>\n";
		}
		$filter .= "<td><b>".$t->translate("Last name")."</b></td>\n"
		."<td><b>".$t->translate("First name")."</b></td>\n"
		."</tr><tr>\n"

		."<td><input type=\"SUBMIT\" name=\"go\" value=\"".$t->translate("Go")."\"></td>\n";
		if ($conid <= 0) {
			$filter .= "<td><input type=\"TEXT\" name=\"name\" value=\"$name\" size=10 maxlength=255></td>\n";
		}
		$filter .= "<td><input type=\"TEXT\" name=\"lastname\" value=\"$lastname\" size=10 maxlength=64></td>\n"
		."<td><input type=\"TEXT\" name=\"firstname\" value=\"$firstname\" size=10 maxlength=64></td>\n"

		."</tr><tr>\n"
		."<td></td>\n"
		."<td><b>".$t->translate("Grad")."</b></td>\n"
		."<td><b>".$t->translate("Position")."</b></td>\n"
		."<td><b>".$t->translate("Comment")."</b></td>\n"
		."</tr><tr>\n"

		."<td></td>\n"
		."<td><input type=\"TEXT\" name=\"grad\" value=\"$grad\" size=10 maxlength=64></td>\n"
		."<td><input type=\"TEXT\" name=\"position\" value=\"$position\" size=10 maxlength=64></td>\n"
		."<td><input type=\"TEXT\" name=\"comment\" value=\"$comment\" size=10 maxlength=255></td>\n";
		if ($conid > 0) {
			$filter .= "<input type=\"hidden\" name=\"id\" value=\"$conid\">\n";
		}
		$filter .= "<input type=\"hidden\" name=\"by\" value=\"filter\">\n"
		."</form></tr></table>\n";
		$bs->box_strip($filter);
	}
}


function pernav($db,$conid) {
	global $PHP_SELF,$sess,$t,$bs,$config_showfull_perperpage;
    global $by,$cnt,$prev_cnt,$next_cnt,$name,$firstname,$lastname,$grad,$position,$comment;
	if ($db->num_rows() > 0 && ($cnt > 0 || $db->num_rows() == $config_showfull_perperpage)) {
		if ($conid > 0) {
			$ref = "perbyconid.php";
		} else {
			$ref = basename($PHP_SELF);
		}
		if ($db->num_rows() == $config_showfull_perperpage) {
			$nav = "&lt;&nbsp;<a href=\"".$sess->url($ref);
			if ($conid > 0) {
				$parray["id"] = $conid;
			}
			$parray["cnt"] = $prev_cnt;
			$parray["by"] = $by;
			$parray["name"] = $name;
			$parray["firstname"] = $firstname;
			$parray["lastname"] = $lastname;
			$parray["grad"] = $grad;
			$parray["position"] = $position;
			$parray["comment"] = $comment;
			$nav .= $sess->add_query($parray)."\">".$t->translate("Previous")."</a>";
		} else {
			$nav = "&lt;&nbsp;".$t->translate("Previous")."</a>";
		}
		$nav .= " | <a href=\"".$sess->url($ref);
		if ($conid > 0) {
			$tarray["id"] = $conid;
		}
		$tarray["by"] = $by;
		$tarray["name"] = $name;
		$tarray["firstname"] = $firstname;
		$tarray["lastname"] = $lastname;
		$tarray["grad"] = $grad;
		$tarray["position"] = $position;
		$tarray["comment"] = $comment;
		$nav .= $sess->add_query($tarray)."\">".$t->translate("Top")."</a>";

		if ($cnt > 0) {
			$nav .= " | <a href=\"".$sess->url($ref);
			if ($conid > 0) {
				$narray["id"] = $conid;
			}
			$narray["cnt"] = $next_cnt;
			$narray["by"] = $by;
			$narray["name"] = $name;
			$narray["firstname"] = $firstname;
			$narray["lastname"] = $lastname;
			$narray["grad"] = $grad;
			$narray["position"] = $position;
			$narray["comment"] = $comment;
			$nav .= $sess->add_query($narray)."\">".$t->translate("Next")."</a>&nbsp;&gt;";
		} else {
			$nav .= " | ".$t->translate("Next")."&nbsp;&gt;";
		}
		$bs->box_strip($nav);
	}
}


function pernum($conid) {
	$dbcnt = new DB_SourceContact;
	$columns = "COUNT(*) AS cnt";
	$tables = "persons";
	$where = "conid_per='$conid'";
	$dbcnt->query("SELECT $columns FROM $tables WHERE $where");
	if ($dbcnt->next_record()) {
		return $dbcnt->f("cnt");
	} else {
		return 0;
	}
}

?>
