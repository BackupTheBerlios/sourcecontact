<?php

function claform($db) {
    global $sess, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate($db->f("category"))." ".$t->translate("Categories")." ".$t->translate("of")." \"".$db->f("name")."\"");
	$bx->box_body_begin();
    echo "<form action=\"".$sess->url("clains.php")."\" method=\"GET\">\n";
	echo "<select multiple name=\"classes[]\" size=10>\n";
	select_mcat($db->f("category"),0);
	echo "</select>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("conid")."\">\n";
    echo "<input type=\"hidden\" name=\"type\" value=\"".$db->f("category")."\">\n";
    echo "<br><input type=\"Submit\" value=\"".$t->translate("Go")."\">\n";
    echo "</form>\n";
	$bx->box_body_end();
	$bx->box_end();
}


function clamod($db) {
	global $sess, $bx, $t;
	$bx->box_begin();
	$bx->box_title($t->translate($db->f("type"))." ".$t->translate("Categories")." ".$t->translate("of")." \"".$db->f("name")."\"");
	$bx->box_body_begin();
    echo "<form action=\"".$sess->url("claupd.php")."\" method=\"GET\">\n";
	echo "<select multiple name=\"classes[]\" size=10>\n";
	select_mcat($db->f("type"),$db->f("conid"));
	echo "</select>\n";
    echo "<input type=\"hidden\" name=\"id\" value=\"".$db->f("conid")."\">\n";
    echo "<input type=\"hidden\" name=\"type\" value=\"".$db->f("type")."\">\n";
    echo "<br><input type=\"Submit\" value=\"".$t->translate("Go")."\">\n";
    echo "</form>\n";
	$bx->box_body_end();
	$bx->box_end();
}

function clashow($conid,$type) {
	$dbcla = new DB_SourceContact;
    $columns = "class";
    $tables = "classifications";
    $where = "conid='$conid' AND type = '$type'";
	$class = "unknown";
    if ($dbcla->query("SELECT $columns FROM $tables WHERE $where")) {
		if ($dbcla->num_rows() > 0) {
			$dbcla->next_record();
			$class = $dbcla->f("class");
			if (empty($class)) {
				$class = "unknown";
			} else {
				$class = ereg_replace(",", ", ", $class);
			}
		}
	}
	return $class;
}

?>
