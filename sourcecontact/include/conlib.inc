<?php

function conform($db) {
    global $sess, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate("Insert Contact"));
	$bx->box_body_begin();
    echo "<form action=\"".$sess->url("conins.php")."\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right>".$t->translate("Name")." (255):</td><td><b>".$GLOBALS["name"]."</b></td></tr>\n";
    echo "<input type=\"hidden\" name=\"name\" value=\"".$GLOBALS["name"]."\">\n";
    echo "<tr><td align=right>".$t->translate("Category")." (64):</td>\n";
    echo "<td><select name=\"category\">\n";
    select_cat("Contact","");
    echo "</select></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Address")." (255):</td><td><input type=\"TEXT\" name=\"address\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Country")." (128):</td><td><input type=\"TEXT\" name=\"country\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("State")." (128):</td><td><input type=\"TEXT\" name=\"state\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("City")." (128):</td><td><input type=\"TEXT\" name=\"city\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("ZIP")." (16):</td><td><input type=\"TEXT\" name=\"zip\" size=40 maxlength=16></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Phone")." (128):</td><td><input type=\"TEXT\" name=\"phone\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Fax")." (128):</td><td><input type=\"TEXT\" name=\"fax\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Email")." (128):</td><td><input type=\"TEXT\" name=\"email\" size=40 maxlength=128></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Homepage")." (255):</td><td><input type=\"TEXT\" name=\"homepage\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Comment")." (255):</td><td><input type=\"TEXT\" name=\"comment\" size=40 maxlength=255></td></tr>\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Go")."\"></td>\n";
    echo "</form>\n";
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function conshow($db,$admin) {
    global $sess, $t, $bx, $sys_logo_url;
	$bx->box_begin();
	$bx->box_title($t->translate("Contact"));
	$bx->box_body_begin();
	if ($admin || $db->f("status") == 'A') {
	    echo "<table border=0 cellspacing=1 cellpadding=3 bgcolor=".$GLOBALS["th_box_body_bgcolor"].">\n";
		$name = $db->f("name");
		if (!empty($name)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Name").":</b></td><td>".$db->f("name")."</td></tr>\n";
		}
		$category = $db->f("category");
		if (!empty($category)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Category").":</b></td><td>".$db->f("category")."</td></tr>\n";
    	}
		$address = $db->f("address");
		if (!empty($address)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Address").":</b></td><td>".$db->f("address")."</td></tr>\n";
    	}
		$country = $db->f("country");
		if (!empty($country)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Country").":</b></td><td>".$db->f("country")."</td></tr>\n";
    	}
		$state = $db->f("state");
		if (!empty($state)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("State").":</b></td><td>".$db->f("state")."</td></tr>\n";
    	}
		$city = $db->f("city");
		if (!empty($city)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("City").":</b></td><td>".$db->f("city")."</td></tr>\n";
    	}
		$zip = $db->f("zip");
		if (!empty($zip)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("ZIP").":</b></td><td>".$db->f("zip")."</td></tr>\n";
    	}
		$phone = $db->f("phone");
		if (!empty($phone)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Phone").":</b></td><td>".$db->f("phone")."</td></tr>\n";
    	}
		$fax = $db->f("fax");
		if (!empty($fax)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Fax").":</b></td><td>".$db->f("fax")."</td></tr>\n";
    	}
		$email = $db->f("email");
		if (!empty($email)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Email").":</b></td><td>&lt;<a href=\"mailto:".$db->f("email")."\">".ereg_replace("@"," at ",htmlentities($db->f("email")))."</a>&gt;</td></tr>\n";
		}
		$homepage = $db->f("homepage");
		if (!empty($homepage)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Homepage").":</b></td><td>&lt;<a href=\"".$db->f("homepage")."\" target=_blank>".$db->f("homepage")."</a>&gt;</td></tr>\n";
		}
		$comment = $db->f("comment");
		if (!empty($comment)) {
    		echo "<tr valign=top><td align=right><b>".$t->translate("Comment").":</b></td><td>".$db->f("comment")."</td></tr>\n";
    	}
    	echo "<tr valign=top><td align=right><b>".$t->translate("Classification").":</b></td><td>".clashow($db->f("conid"),$db->f("category"));
		if ($admin) {
		    echo " <b>[<a href=\"".$sess->url("claadd.php").$sess->add_query(array("id" => $db->f("conid"),"type" => $db->f("category")))."\">".$t->translate("Select")."</a>]</b></td></tr>\n";
		}
	    echo "</table>\n";
	}
    echo "<p><b>[ <a href=\"".$sess->url("perbyconid.php").$sess->add_query(array("id" => $db->f("conid")))."\">".$t->translate("Contact Persons")."</a> [".pernum($db->f("conid"))."] ]</b>\n";
    $timestamp = mktimestamp($db->f("modification"));
    echo "<p class=\"small\"><b>".$t->translate("by")." <a href=\"mailto:".$db->f("email_usr")."\">".$db->f("user")."</a> - ".timestr($timestamp)."</b>\n";
	$bx->box_body_end();
	if ($admin || $db->f("status") == 'D') {
		$bx->box_title_begin();
		if ($db->f("status") == 'D') {
			if ($admin) {
		    	echo "<a href=\"".$sess->url("conupd.php").$sess->add_query(array("id" => $db->f("conid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update Contact")."\"></a>\n";
				echo "&nbsp;&nbsp;";
				echo "<a href=\"".$sess->url("conupd.php").$sess->add_query(array("id" => $db->f("conid")))."\">";
			}
			echo "<img src=\"images/editdelete.png\" border=0 alt=\"";
			if ($admin) {
				echo $t->translate("Undelete")."\"></a>\n";
			} else {
				echo $t->translate("Deleted")."\">\n";
			}
		} else {
			if ($admin) {
		    	echo "<a href=\"".$sess->url("conupd.php").$sess->add_query(array("id" => $db->f("conid")))."\"><img src=\"images/recycled.png\" border=0 alt=\"".$t->translate("Update Contact")."\"></a>\n";
		    	echo "&nbsp;&nbsp;<b>".$t->translate("Add").":&nbsp;[&nbsp;<a href=\"".$sess->url("peradd.php").$sess->add_query(array("id" => $db->f("conid")))."\">".$t->translate("Contact Person")."</a>&nbsp;]</b>\n";
			}
		}
		$bx->box_title_end();
	}
	$bx->box_end();
}

function conmod($db) {
   global $sess, $perm, $t, $bx;
	$bx->box_begin();
	$bx->box_title($t->translate("Contact")." ".$t->translate("of")." \"".$db->f("name")."\"");
	$bx->box_body_begin();
    echo "<form action=\"".$sess->self_url()."\" method=\"POST\">\n";
    echo "<table border=0 align=center cellspacing=0 cellpadding=3>\n";
    echo "<tr><td align=right>".$t->translate("Name")." (255):</td><td><input type=\"TEXT\" name=\"name\" size=40 maxlength=255 value=\"".$db->f("name")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Category")." (64):</td>\n";
    echo "<td><select name=\"category\">\n";
    select_cat("Contact",$db->f("category"));
    echo "</select></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Address")." (255):</td><td><input type=\"TEXT\" name=\"address\" size=40 maxlength=255 value=\"".$db->f("address")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Country")." (128):</td><td><input type=\"TEXT\" name=\"country\" size=40 maxlength=128 value=\"".$db->f("country")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("State")." (128):</td><td><input type=\"TEXT\" name=\"state\" size=40 maxlength=128 value=\"".$db->f("state")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("City")." (128):</td><td><input type=\"TEXT\" name=\"city\" size=40 maxlength=128 value=\"".$db->f("city")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("ZIP")." (16):</td><td><input type=\"TEXT\" name=\"zip\" size=40 maxlength=16 value=\"".$db->f("zip")."\"</td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Phone")." (128):</td><td><input type=\"TEXT\" name=\"phone\" size=40 maxlength=128 value=\"".$db->f("phone")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Fax")." (128):</td><td><input type=\"TEXT\" name=\"fax\" size=40 maxlength=128 value=\"".$db->f("fax")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Email")." (128):</td><td><input type=\"TEXT\" name=\"email\" size=40 maxlength=128 value=\"".$db->f("email")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Homepage")." (255):</td><td><input type=\"TEXT\" name=\"homepage\" size=40 maxlength=255 value=\"".$db->f("homepage")."\">";
	$homepage = $db->f("homepage");
	if (!empty($homepage)) {
		echo "&nbsp;[<a href=\"".$db->f("homepage")."\" target=\"_blank\">".$t->translate("Check")."</a>]";
	}
	echo "</td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Comment")." (255):</td><td><input type=\"TEXT\" name=\"comment\" size=40 maxlength=255 value=\"".$db->f("comment")."\"></td></tr>\n";
    echo "<tr><td align=right>".$t->translate("Status")." :</td><td>";
	switch ($db->f("status")) {
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
	if ($db->f("status") == 'A') {
		echo "<option value=\"delete\"";
		echo ">".$t->translate("Delete")."\n";
	}
	if ($db->f("status") == 'D') {
		echo "<option value=\"undelete\"";
		echo ">".$t->translate("Undelete")."\n";
	}
	if ($perm->have_perm("admin")) {
		echo "<option value=\"erase\"";
		echo ">".$t->translate("Erase")."\n";
	}
	echo "</select></td></tr>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("conid")."\">\n";
    echo "<input type=\"hidden\" name=\"status\" value=\"".$db->f("status")."\">\n";
    echo "<tr><td align=right>&nbsp;</td><td><input type=\"Submit\" value=\"".$t->translate("Go")."\"></td>\n";
    echo "</form>\n";
    echo "</tr></table>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function conbyname($db,$name) {
	global $t, $be, $auth, $perm;
	$columns = "contact.*,auth_user.email_usr";
	$tables = "contact,auth_user";
	$where = "contact.name='$name' AND auth_user.username = contact.user";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
		mysql_die($db);
	} else {
		if ($db->next_record()) {
			conshow($db,admin($db));
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Contact")." (ID: $conid) ".$t->translate("does not exist").".");
		}
	}
}


function conbyconid($db,$conid) {
	global $t, $be, $auth, $perm;
	$columns = "contact.*,auth_user.email_usr";
	$tables = "contact,auth_user";
	$where = "conid='$conid' AND auth_user.username = contact.user";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where")) {
		mysql_die($db);
	} else {
		if ($db->next_record()) {
			conshow($db,admin($db));
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Contact")." (ID: $conid) ".$t->translate("does not exist").".");
		}
	}
}


function conbyperid($db,$perid) {
	global $t, $be, $auth, $perm;
	$columns = "*";
	$tables = "persons,contact,auth_user";
	$where = "persons.perid='$perid' AND contact.conid=persons.conid_per AND contact.user=auth_user.username";
	$group = "persons.perid";
	if (!$db->query("SELECT $columns FROM $tables WHERE $where GROUP BY $group")) {
		mysql_die($db);
	} else {
		if ($db->next_record()) {
			conshow($db,admin($db));
		} else {
			$be->box_full($t->translate("Error"), $t->translate("Contact Person")." (ID: $perid) ".$t->translate("does not exist").".");
		}
	}
}


function conidx($num) {
	global $sess, $t, $db, $bx;
    $columns = "*";
    $tables = "contact";
    $where = "contact.status='A'";
    $order = "contact.modification DESC";
    $limit = "0,".$num;
    if (!$db->query("SELECT $columns FROM $tables WHERE $where ORDER BY $order LIMIT $limit"))
    {
        mysql_die($db);
    } else {
        if ($db->num_rows() > 0) {
			$bx->box_begin();
			$bx->box_title_begin();
            echo "<center><b>".$t->translate("Contacts")."</b></center></a>";
			$bx->box_title_end();
			$bx->box_body_begin();
            while($db->next_record()) {
                echo "<li class=\"small\"><a href=\"".$sess->url("conbyconid.php").$sess->add_query(array("id" => $db->f("conid")))."\">".$db->f("name")."</a> (".$db->f("category").")</li>\n";
            }
			$bx->box_body_end();
			$bx->box_end();
        }
    }
}


function conquery() {
    global $by,$cnt,$name,$category,$address,$country,$state,$city,$zip,$class,$author;
    global $auth, $logout, $bs, $config_showfull_conperpage;
	$columns = "contact.*,auth_user.email_usr";
	$tables = "contact,auth_user";
	if (isset($class) && !empty($class)) {
		$columns .= ",classifications.class";
		$tables .= ",classifications";
	}
	$like = "";
	switch ($by) {
	case "name":
		$order = "ORDER BY contact.name ASC";
		break;			
	case "filter":
		$order = "";
		if (isset($name) && !empty($name)) {
			$like .= " AND contact.name LIKE '%$name%'";
		}
		if (isset($category) && !empty($category)) {
			$like .= " AND contact.category LIKE '%$category%'";
		}
		if (isset($address) && !empty($address)) {
			$like .= " AND contact.address LIKE '%$address%'";
		}
		if (isset($country) && $country != "%") {
			$like .= " AND contact.country LIKE '$country'";
		}
		if (isset($state) && $state != "%") {
			$like .= " AND contact.state LIKE '$state'";
		}
		if (isset($city) && $city != "%") {
			$like .= " AND contact.city LIKE '$city'";
		}
		if (isset($zip) && !empty($zip)) {
			$like .= " AND contact.zip LIKE '%$zip%'";
		}
		if (isset($class) && !empty($class)) {
			$like .= " AND classifications.class LIKE '%$class%'";
		}
		if (isset($author) && !empty($author)) {
			$like .= " AND contact.user LIKE '%$author%'";
		}
		break;			
	case "user":
		if (isset($auth)) {
			$like .= " AND contact.user='".$auth->auth["uname"]."'";
		}
		break;
	case "date":
	default:
		$order = "ORDER BY contact.modification DESC";
		break;
	}
	$where = "auth_user.username = contact.user";
	if (isset($class) && !empty($class)) {
		$where .= " AND classifications.conid = contact.conid";
	}
	$where .= $like;
	
	if (!isset($auth) || empty($auth->auth["perm"]) || $logout) {
		$where .= " AND contact.status='A'";
	}
	$limit = $cnt.",".$config_showfull_conperpage;
	return "SELECT $columns FROM $tables WHERE $where $order LIMIT $limit";
}


function consort($db) {
	global $PHP_SELF,$sess,$t,$bs,$config_showfull_conperpage;
    global $by,$cnt,$prev_cnt,$next_cnt,$name,$category,$address,$country,$state,$city,$zip,$class,$author;
	$ref = basename($PHP_SELF);
	$sort = $t->translate("Contacts")." ".$t->translate("sorted by").": ";
	if (!empty($by) && $by != "date") {
		$sort .= "<a href=\"".$sess->url($ref);
		$darray["by"] = "date";
		$sort .= $sess->add_query($darray)."\">".$t->translate("Date")."</a>";
	} else {
		$sort .= $t->translate("Date");
	}
	$sort .= " | ";
	if ($by != "name") {
		$sort .= "<a href=\"".$sess->url($ref);
		$narray["by"] = "name";
		$sort .= $sess->add_query($narray)."\">".$t->translate("Name")."</a>";
	} else {
		$sort .= "".$t->translate("Name");
	}
	$sort .= " | ";
	if ($by != "filter") {
		$sort .= "<a href=\"".$sess->url($ref);
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
		$filter .= "<td><b>".$t->translate("Name")."</b></td>\n"
		."<td><b>".$t->translate("Category")."</b></td>\n"
		."</tr><tr>\n"

		."<td><input type=\"SUBMIT\" name=\"go\" value=\"".$t->translate("Go")."\"></td>\n";
		$filter .= "<td><input type=\"TEXT\" name=\"name\" value=\"$name\" size=10 maxlength=255></td>\n"
		."<td><select name=\"category\">\n"
		."<option value=\"%\">".$t->translate("All")."\n"
		.select_form('contact','category',$category)
		."</select></td>\n"

		."</tr><tr><td></td>\n"
		."<td><b>".$t->translate("Address")."</b></td>\n"
		."<td><b>".$t->translate("Country")."</b></td>\n"

		."</tr><tr><td></td>\n"
		."<td><input type=\"TEXT\" name=\"address\" value=\"$address\" size=10 maxlength=255></td>\n"
		."<td><select name=\"country\">\n"
		."<option value=\"%\">".$t->translate("All")."\n"
		.select_form('contact','country',$country)
		."</select></td>\n"

		."</tr><tr><td></td>\n"
		."<td><b>".$t->translate("State")."</b></td>\n"
		."<td><b>".$t->translate("City")."</b></td>\n"

		."</tr><tr><td></td>\n"
		."<td><select name=\"state\">\n"
		."<option value=\"%\">".$t->translate("All")."\n"
		.select_form('contact','state',$state)
		."</select></td>\n"
		."<td><select name=\"city\">\n"
		."<option value=\"%\">".$t->translate("All")."\n"
		.select_form('contact','city',$city)
		."</select></td>\n"

		."</tr><tr><td></td>\n"
		."<td><b>".$t->translate("ZIP")."</b></td>\n"
		."<td><b>".$t->translate("Author")."</b></td>\n"

		."</tr><tr><td></td>\n"
		."<td><input type=\"TEXT\" name=\"zip\" value=\"$zip\" size=10 maxlength=16></td>\n"
        ."<td><input type=\"TEXT\" name=\"author\" value=\"$author\" size=10 maxlength=16></td>"

		."</tr><tr><td></td>\n"
		."<td colspan=2><b>".$t->translate("Classification")."</b></td>\n"

		."</tr><tr><td></td>\n"
		."<td colspan=2><select name=\"class\">\n"
		."<option value=\"\">".$t->translate("All")."\n"
		.select_form('classifications','class',$class)
		."</select></td>\n"

		."<input type=\"hidden\" name=\"by\" value=\"filter\">\n"
		."</form></tr></table>\n";
		$bs->box_strip($filter);
	}
}


function connav($db) {
	global $PHP_SELF,$sess,$t,$bs,$config_showfull_conperpage;
    global $by,$cnt,$prev_cnt,$next_cnt,$name,$category,$address,$country,$state,$city,$zip,$class;
	if ($db->num_rows() > 0 && ($cnt > 0 || $db->num_rows() == $config_showfull_conperpage)) {
		$ref = basename($PHP_SELF);
		if ($db->num_rows() == $config_showfull_conperpage) {
			$nav = "&lt;&nbsp;<a href=\"".$sess->url($ref);
			$parray["cnt"] = $prev_cnt;
			$parray["by"] = $by;
			$parray["name"] = $name;
			$parray["category"] = $category;
			$parray["address"] = $address;
			$parray["country"] = $country;
			$parray["state"] = $state;
			$parray["city"] = $city;
			$parray["zip"] = $zip;
			$parray["class"] = $class;
			$nav .= $sess->add_query($parray)."\">".$t->translate("Previous")."</a>";
		} else {
			$nav = "&lt;&nbsp;".$t->translate("Previous")."</a>";
		}
		$nav .= " | <a href=\"".$sess->url($ref);
		$tarray["by"] = $by;
		$tarray["name"] = $name;
		$tarray["category"] = $category;
		$tarray["address"] = $address;
		$tarray["country"] = $country;
		$tarray["state"] = $state;
		$tarray["city"] = $city;
		$tarray["zip"] = $zip;
		$tarray["class"] = $class;
		$nav .= $sess->add_query($tarray)."\">".$t->translate("Top")."</a>";

		if ($cnt > 0) {
			$nav .= " | <a href=\"".$sess->url($ref);
			$narray["cnt"] = $next_cnt;
			$narray["by"] = $by;
			$narray["name"] = $name;
			$narray["category"] = $category;
			$narray["address"] = $address;
			$narray["country"] = $country;
			$narray["state"] = $state;
			$narray["city"] = $city;
			$narray["zip"] = $zip;
			$narray["class"] = $class;
			$nav .= $sess->add_query($narray)."\">".$t->translate("Next")."</a>&nbsp;&gt;";
		} else {
			$nav .= " | ".$t->translate("Next")."&nbsp;&gt;";
		}
		$bs->box_strip($nav);
	}
}


function erase($conid) {
        $dbsvc = new DB_SourceContact;
        $tables = "classifications";
        $where = "conid='$conid'";
        $dbsvc->query("DELETE FROM $tables WHERE $where");
}

?>
