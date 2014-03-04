<?php
/**
* phpBB_SEO Class
* www.phpBB-SEO.com
* @package Advanced phpBB3 SEO mod Rewrite
*/
if (!defined('IN_PHPBB')) {
	exit;
}
$this->cache_config['settings'] = array ( 'url_rewrite' => true, 'modrtype' => 3, 'profile_inj' => true, 'profile_vfolder' => false, 'profile_noids' => false, 'rewrite_usermsg' => false, 'rem_sid' => true, 'rem_hilit' => true, 'rem_small_words' => true, 'virtual_folder' => false, 'virtual_root' => false, 'cache_layer' => true, 'rem_ids' => true, 'copyrights' => array ( 'img' => false, 'txt' => '', 'title' => '', ), 'no_dupe' => array ( 'on' => true, ), 'zero_dupe' => array ( 'on' => false, 'strict' => true, 'post_redir' => 'off', ), );
$this->cache_config['forum'] = array ( 1 => 'gestion-vos-projets', 2 => 'creer-son-projet', 3 => 'adherer-projet', 4 => 'offres-demandes', 5 => 'cherche-quelqu', 6 => 'projet', );
?>