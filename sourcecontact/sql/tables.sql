# phpMyAdmin MySQL-Dump
# http://phpwizard.net/phpMyAdmin/
#
# Host: db Database : sourcecontact

# --------------------------------------------------------
#
# Table structure for table 'active_sessions'
#

CREATE TABLE active_sessions (
   sid varchar(32) NOT NULL,
   name varchar(32) NOT NULL,
   val text,
   changed varchar(14) NOT NULL,
   PRIMARY KEY (name, sid),
   KEY changed (changed)
);

# --------------------------------------------------------
#
# Table structure for table 'auth_user'
#

CREATE TABLE auth_user (
   user_id varchar(32) NOT NULL,
   username varchar(32) NOT NULL,
   password varchar(32) NOT NULL,
   realname varchar(64) NOT NULL,
   email_usr varchar(128) NOT NULL,
   modification_usr timestamp(14),
   creation_usr timestamp(14),
   perms varchar(255),
   PRIMARY KEY (user_id),
   UNIQUE k_username (username)
);

#
# Dumping data for table 'auth_user'
#

INSERT INTO auth_user VALUES ( '84ad96f5486a0fd156e50a613c31c6a9', 'admin', 'admin', 'Adminstrator', 'admin@nowhere.nowhere', '20010627145900', '20010627145746', 'user,admin');
INSERT INTO auth_user VALUES ( 'f00db93bbaee834da1ab30ec8dc9057a', 'guest', 'guest', 'Guest user', 'guest@nowhere.nowhere', '20010628123407', '20010628123354', 'user');

# --------------------------------------------------------
#
# Table structure for table 'categories'
#

CREATE TABLE categories (
   catid bigint(20) unsigned DEFAULT '0' NOT NULL auto_increment,
   type varchar(64) NOT NULL,
   category varchar(255) NOT NULL,
   PRIMARY KEY (catid),
   UNIQUE catid (catid)
);

#
# Dumping data for table 'categories'
#

INSERT INTO categories VALUES ( '1', 'Contact', 'Anwender');
INSERT INTO categories VALUES ( '4', 'Contact', 'Hersteller und Dienstleister');
INSERT INTO categories VALUES ( '6', 'Hersteller und Dienstleister', 'Software Products');
INSERT INTO categories VALUES ( '5', 'Hersteller und Dienstleister', 'Consulting');
INSERT INTO categories VALUES ( '7', 'Hersteller und Dienstleister', 'Open Source Software');
INSERT INTO categories VALUES ( '8', 'Hersteller und Dienstleister', 'Projects and Solutions');
INSERT INTO categories VALUES ( '9', 'Hersteller und Dienstleister', 'Maintenance');
INSERT INTO categories VALUES ( '10', 'Hersteller und Dienstleister', 'Support');
INSERT INTO categories VALUES ( '11', 'Hersteller und Dienstleister', 'Training');
INSERT INTO categories VALUES ( '16', 'Hersteller und Dienstleister', 'Distributor');
INSERT INTO categories VALUES ( '15', 'Hersteller und Dienstleister', 'Systems');
INSERT INTO categories VALUES ( '14', 'Hersteller und Dienstleister', 'Operating');
INSERT INTO categories VALUES ( '53', 'Anwender', 'Bildungswesen');
INSERT INTO categories VALUES ( '54', 'Anwender', 'Parteien; Verbände; Vereine');
INSERT INTO categories VALUES ( '19', 'Anwender', 'Energiewirtschaft');
INSERT INTO categories VALUES ( '20', 'Anwender', 'Abfallwirtschaft');
INSERT INTO categories VALUES ( '21', 'Anwender', 'Industrie; Chemie');
INSERT INTO categories VALUES ( '22', 'Anwender', 'Industrie; Pharma');
INSERT INTO categories VALUES ( '23', 'Anwender', 'Industrie; Kunststoff');
INSERT INTO categories VALUES ( '24', 'Anwender', 'Versorgungswirtschaft');
INSERT INTO categories VALUES ( '25', 'Anwender', 'Industrie; Laborsysteme');
INSERT INTO categories VALUES ( '26', 'Anwender', 'Industrie; Betonwerke; Kieswerke');
INSERT INTO categories VALUES ( '27', 'Anwender', 'Industrie; Metall');
INSERT INTO categories VALUES ( '28', 'Anwender', 'Industrie; Maschinenbau');
INSERT INTO categories VALUES ( '29', 'Anwender', 'Industrie, Zulieferer');
INSERT INTO categories VALUES ( '30', 'Anwender', 'Industrie; Luftfahrt');
INSERT INTO categories VALUES ( '31', 'Anwender', 'Industrie; Möbel');
INSERT INTO categories VALUES ( '32', 'Anwender', 'Industrie; Glas');
INSERT INTO categories VALUES ( '33', 'Anwender', 'Industrie; Textil; Bekleidung');
INSERT INTO categories VALUES ( '34', 'Anwender', 'Industrie; Graphik; Druckereien');
INSERT INTO categories VALUES ( '35', 'Anwender', 'Industrie; Papier');
INSERT INTO categories VALUES ( '36', 'Anwender', 'Industrie; Verpackung');
INSERT INTO categories VALUES ( '37', 'Anwender', 'Industrie; Lebensmittel; Nahrungsmittel');
INSERT INTO categories VALUES ( '38', 'Anwender', 'Industrie; Backwaren');
INSERT INTO categories VALUES ( '39', 'Anwender', 'Industrie; Getränke; Brauereien');
INSERT INTO categories VALUES ( '40', 'Anwender', 'Industrie; verschiedene');
INSERT INTO categories VALUES ( '41', 'Anwender', 'Bauwesen; Architektur; Bauabwicklung; Baurechnungswesen; Baubuchhaltung');
INSERT INTO categories VALUES ( '42', 'Anwender', 'Bauwesen; Architektur; AVA');
INSERT INTO categories VALUES ( '43', 'Anwender', 'Bauwesen; Architektur; Baulohnabrechnung; Baulohnbuchhaltung');
INSERT INTO categories VALUES ( '44', 'Anwender', 'Landwirtschaft; Gartenbau');
INSERT INTO categories VALUES ( '45', 'Anwender', 'Handel');
INSERT INTO categories VALUES ( '46', 'Anwender', 'Verlage; Buchhandel; Zeitschriftenhandel');
INSERT INTO categories VALUES ( '47', 'Anwender', 'Bankwesen; Kreditwesen');
INSERT INTO categories VALUES ( '48', 'Anwender', 'Versicherungswesen');
INSERT INTO categories VALUES ( '49', 'Anwender', 'Transportwesen; Verkehrswesen');
INSERT INTO categories VALUES ( '50', 'Anwender', 'Dienstleistungen');
INSERT INTO categories VALUES ( '51', 'Anwender', 'Gesundheitswesen');
INSERT INTO categories VALUES ( '52', 'Anwender', 'Kommunalwesen; öffentliche Verwaltung');
INSERT INTO categories VALUES ( '55', 'Hersteller und Dienstleister', 'Market Studies');
INSERT INTO categories VALUES ( '56', 'Hersteller und Dienstleister', 'Accessories');

# --------------------------------------------------------
#
# Table structure for table 'classifications'
#

CREATE TABLE classifications (
   conid bigint(20) unsigned DEFAULT '0' NOT NULL,
   type varchar(64) NOT NULL,
   class varchar(255) NOT NULL,
   PRIMARY KEY (conid),
   UNIQUE conid (conid)
);

# --------------------------------------------------------
#
# Table structure for table 'contact'
#

CREATE TABLE contact (
   conid bigint(20) unsigned DEFAULT '0' NOT NULL auto_increment,
   name varchar(255) NOT NULL,
   address varchar(255),
   country varchar(128),
   state varchar(128),
   city varchar(128),
   zip varchar(16),
   phone varchar(128),
   fax varchar(128),
   email varchar(128),
   homepage varchar(255),
   comment varchar(255),
   category varchar(128) NOT NULL,
   user varchar(32) NOT NULL,
   status char(1) NOT NULL,
   modification timestamp(14),
   creation timestamp(14),
   PRIMARY KEY (conid),
   UNIQUE name (name)
);

# --------------------------------------------------------
#
# Table structure for table 'faq'
#

CREATE TABLE faq (
   faqid int(8) unsigned DEFAULT '0' NOT NULL auto_increment,
   language varchar(32) NOT NULL,
   question blob NOT NULL,
   answer blob NOT NULL,
   PRIMARY KEY (faqid),
   UNIQUE faqid (faqid)
);

#
# Dumping data for table 'faq'
#


# --------------------------------------------------------
#
# Table structure for table 'persons'
#

CREATE TABLE persons (
   perid bigint(20) unsigned DEFAULT '0' NOT NULL auto_increment,
   conid_per bigint(20) unsigned DEFAULT '0' NOT NULL,
   salutation_per varchar(16),
   firstname_per varchar(64),
   lastname_per varchar(64) NOT NULL,
   grad_per varchar(64),
   position_per varchar(64),
   phone_per varchar(128),
   fax_per varchar(128),
   email_per varchar(255),
   homepage_per varchar(255),
   comment_per varchar(255),
   status_per char(1) NOT NULL,
   modification_per timestamp(14),
   creation_per timestamp(14),
   PRIMARY KEY (perid),
   UNIQUE perid (perid)
);
