<?php
if ($sess->is_registered("la")) {
   if (isset($lang)) {
      $la = $lang;
   }
} else {
   if (isset($lang)) {
      $la = $lang;
   } else {
      $la = $la_default;
   }
   $sess->register("la");
}
switch($la) {
   case "English": $locale = "en_EN"; break;
   case "German": $locale = "de_DE"; break;
   case "Spanish": $locale = "es_ES"; break;
   default: $locale = "en_EN"; break;
}
setlocale ("LC_TIME", $locale);
?>