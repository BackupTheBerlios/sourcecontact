<?php
class box {
	var $box_width;
	var $box_frame_color;
	var $box_frame_width;
	var $box_title_bgcolor;
	var $box_title_font_color;
	var $box_title_align;
	var $box_body_bgcolor;
	var $box_body_font_color;
	var $box_body_align;

	function box($box_width="",$frame_color="#000000",$frame_width="1",$title_bgcolor="#CCCCCC",$title_font_color="#000000",$title_align="",$body_bgcolor="#FFFFFF",$body_font_color="#000000",$body_align="") {
		$this->box_width = $box_width;
		$this->box_frame_color = $frame_color;
		$this->box_frame_width = $frame_width;
		$this->box_title_bgcolor = $title_bgcolor;
		$this->box_title_font_color = $title_font_color;
		$this->box_title_align = $title_align;
		$this->box_body_bgcolor = $body_bgcolor;
		$this->box_body_font_color = $body_font_color;
		$this->box_body_align = $body_align;
	}
   
	function box_begin() {
		echo "\n<!-- box begin -->\n";
    	echo "<table border=0 cellspacing=0 cellpadding=0 bgcolor=\"$this->box_frame_color\" width=\"$this->box_width\" align=center>\n";
		echo "<tr><td>\n";
		echo "<table border=0 cellspacing=\"$this->box_frame_width\" cellpadding=3 align=\"center\" width=\"100%\">\n";
	}

	function box_end() {
		echo "</table>\n";
		echo "</td></tr></table><br>\n";
		echo "<!-- box end -->\n";
	}

	function box_title_begin() {
		echo "<!-- box title begin -->\n";
		echo "<tr bgcolor=\"$this->box_title_bgcolor\"><td align=\"$this->box_title_align\">\n";
	}

	function box_title_end() {
		echo "</td></tr>\n";
		echo "<!-- box title end -->\n";
	}

	function box_title($title) {
		$this->box_title_begin();
		echo "<font color=\"$this->box_title_font_color\"><b>$title</b></font>\n";
		$this->box_title_end();
	}

	function box_body_begin() {
		echo "<!-- box body begin -->\n";
		echo "<tr bgcolor=\"$this->box_body_bgcolor\"><td align=\"$this->box_body_align\"><font color=\"$this->box_body_font_color\">\n";
	}

	function box_body_end() {
		echo "</font></td></tr>\n";
		echo "<!-- box body end -->\n";
	}

	function box_body($text) {
		$this->box_body_begin();
		echo "$text\n";
		$this->box_body_end();
	}

	function box_full($title, $text) {
		$this->box_begin();
		$this->box_title($title);
		$this->box_body($text);
		$this->box_end();
	}

	function box_strip($title) {
		$this->box_begin();
		$this->box_title($title);
		$this->box_end();
	}
}
?>
