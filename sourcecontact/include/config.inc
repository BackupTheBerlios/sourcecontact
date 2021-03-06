<?php

######################################################################
# SourceContact: Open Source Contact Management
# ================================================
#
# Copyright (c) 2001-2003 by
#                Lutz Henckel (lutz.henckel@fokus.fraunhofer.de)
#
# BerliOS SourceContact: http://sourcecontact.berlios.de
# BerliOS - The OpenSource Mediator: http://www.berlios.de
#
# This is the configuration file
#
# This program is free software. You can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 or later of the GPL.
######################################################################

######################################################################
# System Config
#
# sys_name:			Name of the System
# sys_title:		Your site's slogan
# sys_url_title		URL of the system's portal
# sys_url			System URL
# sys_logo_image	Image of your Site
# sys_logo_alt		Alternative text for your site's image
# sys_logo_width	Width of the image of your site
# sys_logo_heigth	Heigth of the image of your site
# sys_logo_small_image	Small image of your sitebar
# sys_logo_small_alt	Alternative text for your sitebar's image
# sys_logo_small_width	Width of the image of your sitebar
# sys_logo_small_heigth	Heigth of the image of your sitebar
#
# (don't forget to put slashes at the end of the URLs)
######################################################################

$sys_name = "SourceContact";
$sys_title = "Open Source Contact Management";
$sys_url_title = "http://www.berlios.de/";
$sys_url = "http://sourcecontact.berlios.de/sourcecontact/";
$sys_logo_image = "images/berliOS_logo.png";
$sys_logo_alt = "BerliOS";
$sys_logo_width = "238";
$sys_logo_heigth = "61";
#$sys_logo_small_image = "images/berliOS_small_logo.png";
$sys_logo_small_image = "http://developer.berlios.de/bslogo.php?group_id=130&type=1";
$sys_logo_small_alt = $sys_logo_alt;
$sys_logo_small_width = "124";
$sys_logo_small_heigth = "32";
$sys_dir = "/home/groups/sourcecontact/htdocs/sourcecontact/";
$sys_logo_dir = $sys_dir."logos/";
$sys_logo_url = $sys_url."logos/";

######################################################################
# Organisation Config
#
# org_name			Name of your Organisation
# org_url			URL of your Organisation
# org_logo_image	Image of your Organisation
# org_logo_alt		Alternative text for the image of your Organisation
# org_logo_width	Width of the image of your Organisation
# org_logo_heigth	Height of the image of your Organisation
######################################################################

$org_name = "FOKUS";
$org_url = "http://www.fokus.fraunhofer.de/";
$org_logo_image = "images/logo_fokus.png";
$org_logo_alt = $org_name;
$org_logo_width = "60";
$org_logo_heigth = "60";

######################################################################
# Top Strip
#
# You can change (add, delete, modify) the top strip
# as you wish as long as you mantain this syntax:
#
#         "Title"	=> $sys_url_title."URLofYourTitle",
#
# (don't forget that the last one hasn't got a comma!)
#
######################################################################

$ts_array = array (
	"Home"		=> $sys_url_title."index.php",
	"About us"	=> $sys_url_title."about/index.php",
	"Partners"	=> $sys_url_title."partners/index.php",
	"Contact"	=> $sys_url_title."contact/index.php"
);

######################################################################
# Languages
#
# List of languages supported by your website
# You can add/delete/modify as long as you mantain the syntax
# New languages are always wellcome. Contact with the authors!
#
# la_default		Name of default language
# la_array			List of supported languages
######################################################################

$la_default = "German";

$la_array[] = "German";
$la_array[] = "English";
# $la_array[] = "Spanish";

######################################################################
# Theme
#
# Configuration of background colors, font families, etc.
#
######################################################################

$th_body_bgcolor = "#FFFFFF";
$th_font_family = "verdana,arial,helvetica,sans-serif";
$th_tt_font_family = "courier,sans-serif";
$th_font_color = "#333333";
$th_hover_font_color = "#FF0000";

$th_nav_bgcolor = "#FFCC33";
$th_navstrip_bgcolor = "#7B7B7B";
$th_nav_font_color = "#333333";
$th_navstrip_font_color = "#FFFFFF";

$th_box_frame_color = "#CCCCCC";
$th_box_frame_width = "1";
$th_box_title_bgcolor = "#CCCCCC";
$th_box_body_bgcolor = "#FFFFFF";
$th_box_title_align = "left";
$th_box_body_align = "left";
$th_box_title_font_color = "#000000";
$th_box_body_font_color = "#333333";
$th_box_error_font_color = "#FF2020";

$th_strip_frame_color = "#CCCCCC";
$th_strip_frame_width = "1";
$th_strip_title_bgcolor = "#CCCCCC";
$th_strip_body_bgcolor = "";
$th_strip_title_align = "center";
$th_strip_body_align = "";
$th_strip_title_font_color = "#000000";
$th_strip_body_font_color = "";

######################################################################
# Page Layout
#
# config_showfull_conperpage	maximum number of contacts for full shown
# config_showshort_conperpage	maximum number of contacts for short shown
# config_showidx_conperpage		maximum number of contacts for index shown
# config_showfull_perperpage	maximum number of persons for full shown
# config_showshort_perperpage	maximum number of persons for short shown
# config_showidx_perperpage		maximum number of personss for index shown
#
######################################################################

$config_showfull_conperpage = 5;
$config_showshort_conperpage = 25;
$config_showidx_conperpage = 10;
$config_showfull_perperpage = 5;
$config_showshort_perperpage = 25;
$config_showidx_perperpage = 10;

######################################################################
# Email Notification
#
# Notify admin by email that a new user has registered.
#
# ml_notify		To be notified, ml_notify enterprise have to be inserted
# ml_fromaddr	Email address in the From field
# ml_replyaddr	Return Email address
#
######################################################################

$ml_notify = 1;
$ml_fromaddr = "noreply@mail.berlios.de";
$ml_replyaddr = "noreply@mail.berlios.de";

######################################################################
# Newsletter Configuration
#
# ml_listurl			URL of daily news mailing list (mailman)
# ml_weeklylisturl		URL of weekly news mailing list (mailman)
# ml_newstoaddr			Mail address of daily news mailing list
# ml_newsreqaddr		Request mail address of daily news mailing list
# ml_weeklynewstoaddr	Mail address of weekly news mailing list
# ml_weeklynewsreqaddr	Request mail address of weekly news mailing list
# ml_newsadmaddr		News mailing lists administration mail address
# ml_newsfromaddr		News mailing lists from mail address
# ml_newsreplyaddr		News mailing lists reply mail adress
#
######################################################################

$ml_listurl = "http://lists.berlios.de/mailman/listinfo/sourcecontact-news";
$ml_weeklylisturl = "http://lists.berlios.de/mailman/listinfo/sourcecontact-weeklynews";
$ml_newstoaddr = "sourcecontact-news@lists.berlios.de";
$ml_newsreqaddr = "sourcecontact-news-request@lists.berlios.de";
$ml_weeklynewstoaddr = "sourcecontact-weeklynews@lists.berlios.de";
$ml_weeklynewsreqaddr = "sourcecontact-weeklynews-request@lists.berlios.de";
$ml_newsadmaddr = "sourcecontact-admin@lists.berlios.de";
$ml_newsfromaddr = "sourcecontact-crew@berlios.de";
$ml_newsreplyaddr = "noreply@berlios.de";

######################################################################
# Statistic configuration
#
# MinimumEntsByEmail	minimum percentage of an Email domain for
#			being displayed  >= 0.01
# MinimumSecByEmail	the same but for Sections >= 0.01
# MinimumLicByEmail	the same but for Licenses >= 0.01
# Minimum_ents_in_license   minimum amount of enterprises a license has to
#			    have to be displayed in the statistic
#			    "Ents by Licenses and Email Domains"
#			    >= 1
#
######################################################################

$MinimumEntsByEmail = 0.4;
$MinimumSecByEmail = 5;
$MinimumLicByEmail = 1;
$Minimum_ents_in_license = 1;

######################################################################
# Permission for accessing web pages
#
# "user"    only allows access to registered users with user permission
# "admin"   only allows access to registered users with admin permission
# "all"     allows access to everybody (also unregistered users)
#
# Please, be sure of what you make!
# An error could make your system fragile.
#
# config_perm_enterprises	Access permission to enter enterprises.php
# config_perm_contacts		Access permission to enter contacts.php
# config_perm_services		Access permission to enter services.php
# config_perm_products		Access permission to enter products.php
# config_perm_solutions		Access permission to enter solutions.php
# config_perm_news			Access permission to enter news.php
# config_perm_comments		Access permission to enter comments.php
# config_perm_users			Access permission to enter users.php
# config_perm_admuser		Access permission to enter admuser.php
# config_perm_admcat		Access permission to enter admcat.php
# config_perm_admcmt		Access permission to enter admcmt.php
# config_perm_admfaq 		Access permission to enter admfaq.php
# config_perm_nladm			Access permission to enter nladm.php
# 
######################################################################

$config_perm_enterprises = "user";
$config_perm_contacts = "user";
$config_perm_services = "user";
$config_perm_products = "user";
$config_perm_solutions = "user";
$config_perm_news = "user";
$config_perm_comments = "user";
$config_perm_users = "user";
$config_perm_admuser = "admin";
$config_perm_admcat = "admin";
$config_perm_admcmt = "admin";
$config_perm_admfaq = "admin";
$config_perm_nladm = "admin";

######################################################################
# PHPLIB user authorization
#
# Put a random string in it 
######################################################################

$hash_secret = "Jabberwocky...";

######################################################################
# 
# Ok... that's it. You've finished configuring the SourceContact system
#
######################################################################
#
# The rest of parameters that are listed beyond this comment
# are internal or needed for advanced purposes
#
######################################################################

######################################################################
# SourceContact Version
#
# Please, do not touch this in any case!
# It just gives the version of SourceContact you're are using
# You can always download the latest version of SourceContact at
# http://sourcecontact.berlios.de
#
# You can read in the documentation the version number policy followed
# for the SourceContact system development to know when the developers
# recommend you to update your SourceContact system.
#
######################################################################

$SourceContact_Version = "0.0.1";

?>
