<?php
/**
*
* @package phpBB SEO GYM Sitemaps
* @version $id: gymrss.php - 881 11-20-2008 15:05:11 - 2.0.RC1 dcz $
* @copyright (c) 2006 - 2008 www.phpbb-seo.com
* @license http://opensource.org/osi3.0/licenses/lgpl-license.php GNU Lesser General Public License
*
*/
define('IN_PHPBB', true);
$phpEx = substr(strrchr(__FILE__, '.'), 1);
$phpbb_root_path = './';
include($phpbb_root_path . 'common.' . $phpEx);
// Start session management
$user->session_begin();
$auth->acl($user->data);
$user->setup('gym_sitemaps/gym_common');
// Start the process
require($phpbb_root_path . 'gym_sitemaps/includes/gym_rss.' . $phpEx);

$gym_rss  = new gym_rss();
exit;
?>