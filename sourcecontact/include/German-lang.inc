<?php
switch($phrase) {

// Top strip
     case "Home": $tmp = "Heim"; break;
     case "About us": $tmp = "&Uuml;ber uns"; break;
     case "Partners": $tmp = "Partner"; break;
     case "Contact": $tmp = "Kontakt"; break;

     case "Logged in": $tmp = "Eingeloggt als"; break;
     case "Expires": $tmp = "Endet"; break;
     case "Not Logged in": $tmp = "Nicht eingeloggt"; break;

// Top title
     case "Open Source Business":  $tmp = "Open Source Business"; break;

// Menue bar
     case "Q&amp;A": $tmp = "F&amp;A"; break;
     case "Login": $tmp = "Einloggen"; break;
     case "Logout": $tmp = "Ausloggen"; break;
     case "New User": $tmp = "Neuer Benutzer"; break;
     case "Forgot Password": $tmp = "Passwort vergessen"; break;
     case "Change User": $tmp = "Benutzer &auml;ndern"; break;
     case "Users": $tmp = "Benutzer"; break;

     case "New Contact": $tmp = "Neuer Kontakt"; break;
     case "Update Contact": $tmp = "Kontakt aktualisieren"; break;
     case "Categories": $tmp = "Kategorien"; break;

     case "Backend": $tmp = "$phrase"; break;
     case "Statistics": $tmp = "Statistiken"; break;

     case "Administration": $tmp = "Administration"; break;

     case "Search": $tmp = "Suche"; break;
     case "Language": $tmp = "Sprache"; break;
     case "Go": $tmp = "Los"; break;

// Languages
	 case "English": $tmp = "Englisch"; break;
	 case "German": $tmp = "Deutsch"; break;
	 case "Spanish": $tmp = "Spanisch"; break;

// sorted by
	 case "sorted by": $tmp = "sortiert nach"; break;
	 case "Date": $tmp = "Datum"; break;
	 case "Name": $tmp = "Name"; break;
	 case "Importance": $tmp = "Wichtigkeit"; break;
	 case "Filter": $tmp = "Filter"; break;

// navigate
	 case "Previous": $tmp = "Weiter"; break;
	 case "Top": $tmp = "Top"; break;
	 case "Next": $tmp = "Zurück"; break;

// Homepage
     case "Open Source Enterprises, Services, Products and Solutions": $tmp = "Open Source Unternehmen, Dienste, Produkte und Lösungen"; break;
     case "including Profile and Links to further Information": $tmp = "einschließlich Unternehmensprofil und Referenzen zu weiteren Informationen"; break;
     case "including Address, Phone, Email, Homepage, etc.": $tmp = "einschließlich Adresse, Telefon, Email, Homepage, etc."; break;
     case "including Consulting, Education &amp; Training, Projects, Support, etc.": $tmp = "einschließlich Consulting, Schulung &amp; Training, Projekte, Support, etc."; break;
     case "including Software, Hardware, Books, Accessories, etc.": $tmp = "einschließlich Software, Hardware, Bücher, Zubehör, etc."; break;
     case "created by Enterprises for Customers": $tmp = "erstellt von Unternehmen für Kunden"; break;
     case "of Enterprises": $tmp = "der Unternehmen"; break;
     case "provided by Enterprises": $tmp = "von Unternehmen bereitgestellt"; break;
     case "about Enterprises by Users": $tmp = "von Benutzern zu Unternehmen"; break;

// FAQ
     case "Frequently Asked Questions": $tmp = "Oft gestellte Fragen"; break;
     case "Question": $tmp = "Frage"; break;
     case "Answer": $tmp = "Antwort"; break;

// User registration
     case "Register as a new User": $tmp = "Registrierung als neuer Benutzer"; break;
     case "Username": $tmp = "Benutzername"; break;
     case "Password": $tmp = "Passwort"; break;
     case "Confirm Password": $tmp = "Passwort bestätigen"; break;
     case "Realname": $tmp = "Name"; break;
     case "Register": $tmp = "Registrieren"; break;
     case "User Registration": $tmp = "Benutzerregistrierung"; break;
     case "Congratulations": $tmp = "Gratulation"; break;
     case "You have registered on $GLOBALS[sys_name]": $tmp = "Sie haben sich bei $GLOBALS[sys_name] registriert"; break;
     case "Your new username is": $tmp = "Ihr neuer Benutzername ist"; break;
     case "You are now being sent a confirmation email to verify your email address": $tmp = "Es wurde eine Bestätigung per E-Mail an Sie gesendet, um Ihre E-Mail-Adresse zu überprüfen"; break;
     case "Visiting the link sent to you in this email will activate your account": $tmp = "Wenn Sie die in dieser E-Mail gesendete Seite besuchen wird Ihre Benutzerkennung freigeschaltet"; break;
     case "Thank you for registering on the $GLOBALS[sys_name] Site. In order": $tmp = "Danke für Ihre Registrierung bei $GLOBALS[sys_name]. Um Ihre"; break;
     case "to complete your registration, visit the following URL": $tmp = "Registrierung abzuschließen, besuchen Sie die folgende URL"; break;
     case "Enjoy the site": $tmp = "Wir hoffen, dass Ihnen $GLOBALS[sys_name] gefällt"; break;
     case " -- the $GLOBALS[sys_name] crew": $tmp = " -- die $GLOBALS[sys_name] Crew"; break;
     case "Verification of Registration": $tmp = "Verifikation der Registrierung"; break;
     case "Your account is now activated. Please login": $tmp = "Ihre Benutzerkennung ist jetzt freigeschaltet. Bitte loggen Sie sich ein"; break;

// Forget password / Remind me
     case "Register as a new User": $tmp = "Registrierung als neuer Benutzer"; break;
     case "Remind me": $tmp = "Erinnern"; break;
     case "Your Username and Password for $GLOBALS[sys_name] is": $tmp = "Ihr Benutzername und Passwort für $GLOBALS[sys_name] ist"; break;
     case "Please keep this e-mail for further reference": $tmp = "Bitte bewahren Sie diese E-Mail zur späteren Referenzierung auf"; break;
     case "You will get your Password by e-mail in a couple of minutes": $tmp = "Sie erhalten Ihr Passwort per E-Mail in wenigen Minuten"; break;
     case "Attention!": $tmp = "Achtung!"; break;

// Change User Parameters
     case "Change User Parameters": $tmp = "Änderung der Benutzerdaten"; break;
     case "Remind me": $tmp = "Erinnerung"; break;
     case "Modification": $tmp = "Modifiziert"; break;
     case "Creation": $tmp = "Erzeugt"; break;
     case "Permission": $tmp = "Rechte"; break;
     case "Change": $tmp = "Ändern"; break;
     case "Password and/or E-Mail Address of": $tmp = "Passwort und/oder E-Mail-Adresse von"; break;
     case "is changed": $tmp = "wurden geändert"; break;

// Contact
     case "Contacts": $tmp = "Kontakte"; break;
     case "by": $tmp = "von"; break;
     case "Address": $tmp = "Adresse"; break;
     case "Category": $tmp = "Kategorie"; break;
     case "Country": $tmp = "Land"; break;
     case "State": $tmp = "Bundesland"; break;
     case "City": $tmp = "Stadt"; break;
     case "ZIP": $tmp = "PLZ"; break;
     case "Phone": $tmp = "Telefon"; break;
     case "Classification": $tmp = "Klassifikation"; break;
     case "Select": $tmp = "Auswählen"; break;
     case "Add": $tmp = "Erstelle"; break;
     case "Insert": $tmp = "Hinzufügen"; break;
     case "Erase": $tmp = "Vernichten"; break;
     case "Undelete": $tmp = "Wiederherstellen"; break;
     case "active": $tmp = "aktiv"; break;
     case "deleted": $tmp = "gelöscht"; break;
     case "Deleted": $tmp = "Gelöscht"; break;
     case "All": $tmp = "Alle"; break;
     case "is erased": $tmp = "ist vernichtet"; break;

// Contact Person
     case "Contact Person": $tmp = "Kontaktperson"; break;
     case "Contact Persons": $tmp = "Kontaktpersonen"; break;
     case "Salutation": $tmp = "Anrede"; break;
     case "First name": $tmp = "Vorname"; break;
     case "Last name": $tmp = "Name"; break;
     case "Grad": $tmp = "Grad"; break;
     case "Position": $tmp = "Position"; break;
     case "Comment": $tmp = "Kommentar"; break;
     case "of": $tmp = "von"; break;
     case "Mr.": $tmp = "Herr"; break;
     case "Mrs.": $tmp = "Frau"; break;

// Login
     case "$GLOBALS[sys_name] Login": $tmp = "Bei $GLOBALS[sys_name] Einloggen"; break;
     case "Welcome to $GLOBALS[sys_name]": $tmp = "Willkommen bei $GLOBALS[sys_name]"; break;
     case "You are logged in as": $tmp = "Sie sind eingeloggt als"; break;
     case "with": $tmp = "mit"; break;
     case "permission": $tmp = "Rechten"; break;
     case "Your authentication is valid until": $tmp = "Ihre Authentifizierung ist gültig bis"; break;

// Logout
     case "You have been logged in as": $tmp = "Sie waren eingeloggt als"; break;
     case "Your authentication was valid until": $tmp = "Ihre Authentifizierung war gültig bis"; break;
     case "This is all over now. You have been logged out": $tmp = "Dies ist nun vorbei. Sie haben sich ausgeloggt"; break;

// Newsletter
     case "Subscribe Newsletter": $tmp = "Newsletter abonnieren"; break;
     case "Subscribe daily Newsletter": $tmp = "Täglichen Newsletter abonnieren"; break;
     case "Subscribe weekly Newsletter": $tmp = "Wöchentlichen Newsletter abonnieren"; break;
     case "Subscribe": $tmp = "Abonnieren"; break;
     case "Send newsletter": $tmp = "Sende Newsletter"; break;
     case "Newsletter was sent at ": $tmp = "Newsletter wurde gesendet am "; break;
     case "You have subscribed to $GLOBALS[sys_name] daily Newsletter": $tmp = "Sie haben den täglichen $GLOBALS[sys_name] Newsletter abonniert"; break;
     case "You have subscribed to $GLOBALS[sys_name] weekly Newsletter": $tmp = "Sie haben den wöchentlichen $GLOBALS[sys_name] Newsletter abonniert"; break;
     case "Daily Newsletter": $tmp = "Täglicher Newsletter"; break;
     case "Weekly Newsletter": $tmp = "Wöchentlicher Newsletter"; break;
     case "daily": $tmp = "täglich"; break;
     case "weekly": $tmp = "wöchentlich"; break;

// Statistics
     case "$GLOBALS[sys_name] Statistics": $tmp = "$GLOBALS[sys_name] Statistiken"; break;	
     case "General $GLOBALS[sys_name] Statistics": $tmp = "Generelle $GLOBALS[sys_name] Statistiken"; break;	
     case "Contacts by Email Domains": $tmp = "Kontakte nach E-Mail-Domainen"; break;	
     case "Contacts by Countries": $tmp = "Kontakte nach Ländern"; break;
     case "Contacts by States": $tmp = "Kontakte nach Bundesländern"; break;
   	 case "Contacts by Cities": $tmp = "Kontakte nach Städten"; break;	
   	 case "Contacts by Categories": $tmp = "Kontakte nach Kategorien"; break;
   	 case "Contacts by Classifications": $tmp = "Kontakte nach Klassifikationen"; break;
   	 case "Contacts by Contact Categories": $tmp = "Kontakte nach Kontaktkategorien"; break;
   	 case "Contacts listed by Email Domain": $tmp = "Kontakte geordnet nach E-Mail-Domainen"; break;
   	 case "Contacts listed by Countries": $tmp = "Kontakte geordnet nach Ländern"; break;
   	 case "Contacts listed by States": $tmp = "Kontakte geordnet nach Bundesländern"; break;
   	 case "Contacts listed by Cities": $tmp = "Kontakte geordnet nach Städten"; break;
   	 case "Contacts listed by Categories": $tmp = "Kontakte geordnet nach Kategorien"; break;
   	 case "Contacts listed by Contact Categories": $tmp = "Kontakte geordnet nach Kontaktkategorien"; break;
   	 case "Contacts listed by Classifications": $tmp = "Kontakte geordnet nach Klassifikationen"; break;
   	 case "Contact Category": $tmp = "Kontaktkategorie"; break;
   	 case "Number of Contacts": $tmp = "Anzahl der Kontakte"; break;
   	 case "Number of Contact Persons": $tmp = "Anzahl der Kontaktpersonen"; break;
   	 case "Number of Insertions and Modifications during last week": $tmp = "Anzahl der Eintragungen und Änderungen während der letzten Woche"; break;
   	 case "Number of Insertions and Modifications during last day": $tmp = "Anzahl der Eintragungen und Änderungen während des letzten Tages"; break;
   	 case "Number of registered Users": $tmp = "Anzahl der registrierten Benutzer"; break;

// Errors
     case "Access denied": $tmp = "Zugriff verweigert"; break;
     case "No Entry found": $tmp = "Kein Eintrag vorhanden"; break;
     case "Error": $tmp = "Fehler"; break;
     case "does not exist": $tmp = "existiert nicht"; break;
     case "Change User Parameters failed": $tmp = "Änderung der Benutzerdaten ist fehlgeschlagen"; break;
     case "No Contact ID specified": $tmp = "Keine Kontakt-ID angegeben"; break;
     case "No Contact Name specified": $tmp = "Kein Kontaktname angegeben"; break;
     case "No Lastname specified": $tmp = "Kein Name angegeben"; break;
     case "Please select": $tmp = "Bitte wählen Sie"; break;
     case "and": $tmp = "und"; break;
     case "User": $tmp = "Benutzer"; break;
     case "already exists": $tmp = "existiert bereits"; break;
     case "Please select a different Username": $tmp = "Bitte wählen Sie einen anderen Benutzernamen"; break;
     case "Please enter": $tmp = "Bitte angeben:"; break;
     case "Either your Username or E-Mail Address is unknown": $tmp = "Entweder Ihr Benutzername oder E-Mail-Adresse ist unbekannt"; break;
     case "Please try again": $tmp = "Bitte versuchen Sie es nochmal"; break;
     case "If you are not yet a registered User, please select": $tmp = "Wenn Sie noch kein registrierter Benutzer sind, wählen Sie bitte"; break;
     case "Verification of Registration failed": $tmp = "Verifikation der Registrierung ist fehlgeschlagen"; break;
     case "User Change failed": $tmp = "Benutzer ändern ist fehlgeschlagen"; break;
     case "Registration of new User failed": $tmp = "Registrierung des neuen Benutzers ist fehlgeschlagen"; break;
     case "Database Access failed": $tmp = "Datenbankzugriff ist fehlgeschlagen"; break;
     case "User Deletion failed": $tmp = "Benutzer Löschen ist fehlgeschlagen"; break;
     case "Either your Username or Password are invalid": $tmp = "Entweder Ihr Benutzername oder Passwort ist falsch"; break;
     case "The passwords are not identical": $tmp = "Die Passworte sind nicht identisch"; break;
     case "Please try again": $tmp = "Bitte versuchen Sie es nochmal"; break;
     case "for Contact": $tmp = "für Kontakt"; break;
     case "Please create one": $tmp = "Bitte neu erstellen"; break;
     case "No more Contact exist": $tmp = "Es existiert kein weiterer Kontakt"; break;
     case "No more Contact Person exist": $tmp = "Es existiert kein weitere Kontaktperson"; break;
     case "No Name specified": $tmp = "Kein Name angegeben"; break;
     case "No Action specified": $tmp = "Kein Aktion angegeben"; break;
     case "A Contact with this name already exist": $tmp = "Ein Kontakt mit diesem Namen existiert bereits"; break;
     case "No Frequently Asked Questions exist": $tmp = "Es existieren keine oft gestellten Fragen"; break;

// User admin
     case "Action": $tmp = "Aktion"; break;
     case "Delete": $tmp = "Löschen"; break;
     case "Create User": $tmp = "Benutzer Erzeugen"; break;
     case "User Creation": $tmp = "Benutzer einrichten"; break;
     case "created": $tmp = "eingerichtet"; break;
     case "User Change": $tmp = "Benutzer ändern"; break;
     case "User Deletion": $tmp = "Benutzer Löschen"; break;
     case "is deleted": $tmp = "wurden gelöscht"; break;

// Categorie admin
     case "Category Administration for": $tmp = "Kategorieadministation für"; break;
     case "Insert a Category": $tmp = "Kategorie hinzufügen"; break;
     case "Rename a Category": $tmp = "Kategorie umbenennen"; break;
     case "Delete a Category": $tmp = "Kategorie löschen"; break;
     case "New Category": $tmp = "Neue Kategorie"; break;
     case "New Category Name": $tmp = "Neuer Kategoriename"; break;
     case "Rename": $tmp = "Umbenennen"; break;
     case "has been added": $tmp = "wurde hinzugefügt"; break;
     case "has been renamed to": $tmp = "wurde umbenannt in"; break;
     case "has been deleted": $tmp = "wurde gelöscht"; break;

// FAQ admin
     case "Frequently Asked Questions Administration": $tmp = "Administration von oft gestellten Fragen"; break;
     case "New Frequently Asked Question": $tmp = "Neue oft gestellte Frage"; break;
     case "Enter a New Frequently Asked Question": $tmp = "Erstellen einer neuen oft gestellten Frage"; break;
     case "Modify a Frequently Asked Question": $tmp = "Ändern einer oft gestellten Frage"; break;
     case "The following FAQ has been inserted": $tmp = "Die folgende oft gestellten Frage wurde erstellt"; break;
     case "The following FAQ has been modified": $tmp = "Die folgende oft gestellten Frage wurde geändert"; break;
     case "The FAQ has been deleted": $tmp = "Die oft gestellten Frage wurde gelöscht"; break;
     case "Do you really want to delete this FAQ? There is no way for undeletion.": $tmp = "Wollen Sie diese oft gestellten Frage wirklich löschen? Es existiert keine Möglichkeit dies rückgängig zu machen."; break;
     case "Yes, Delete": $tmp = "Ja, Löschen"; break;
     case "No, Just Modify": $tmp = "Nein, nur Ändern"; break;
     case "Create": $tmp = "Erstellen"; break;
     case "Modify": $tmp = "Ändern"; break;

// If no translation available, keep the original phrase
     default: $tmp = "$phrase"; break;
}
?>
