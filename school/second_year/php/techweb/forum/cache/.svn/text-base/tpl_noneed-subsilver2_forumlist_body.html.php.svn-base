<div class="tablebg">

<div style="float:left;width:100%;margin:0;padding:0;">
	<div style="float:left;width:530px;">&nbsp;<?php echo ((isset($this->_rootref['L_FORUM'])) ? $this->_rootref['L_FORUM'] : ((isset($user->lang['FORUM'])) ? $user->lang['FORUM'] : '{ FORUM }')); ?>&nbsp;</div>
	<div style="float:left;width:40px;">&nbsp;<?php echo ((isset($this->_rootref['L_TOPICS'])) ? $this->_rootref['L_TOPICS'] : ((isset($user->lang['TOPICS'])) ? $user->lang['TOPICS'] : '{ TOPICS }')); ?>&nbsp;</div>
	<div style="float:left;width:64px;">&nbsp;<?php echo ((isset($this->_rootref['L_POSTS'])) ? $this->_rootref['L_POSTS'] : ((isset($user->lang['POSTS'])) ? $user->lang['POSTS'] : '{ POSTS }')); ?>&nbsp;</div>
	<div style="float:left;width:105px;">&nbsp;<?php echo ((isset($this->_rootref['L_LAST_POST'])) ? $this->_rootref['L_LAST_POST'] : ((isset($user->lang['LAST_POST'])) ? $user->lang['LAST_POST'] : '{ LAST_POST }')); ?>&nbsp;</div>
</div>
	<br />
<?php $_forumrow_count = (isset($this->_tpldata['forumrow'])) ? sizeof($this->_tpldata['forumrow']) : 0;if ($_forumrow_count) {
	for ($_forumrow_i = 0; $_forumrow_i < $_forumrow_count; ++$_forumrow_i){
		$_forumrow_val = &$this->_tpldata['forumrow'][$_forumrow_i]; if ($_forumrow_val['S_IS_CAT']) {  ?><div style="margin-bottom:5px;">
		<div style="width:100%;" class="cat" colspan="2"><h4><a href="<?php echo $_forumrow_val['U_VIEWFORUM']; ?>"><?php echo $_forumrow_val['FORUM_NAME']; ?></a></h4></div>
</div>

<div style="background-image:url(../images/border_hg.gif);background-repeat:no-repeat;width:20px;float:left;height:12px;"></div>
<div style="width:79%;float:left;background-image:url(../images/border_hm.gif);height:12px;"></div>
<div style="width:140px;float:left;background-image:url(../images/border_hd.gif);background-repeat:no-repeat;height:12px;"></div>
	<?php } else if ($_forumrow_val['S_IS_LINK']) {  ?>		
		<div style="float:left;margin:0;padding:0;">
			<div class="row1" style="width:40px;"><?php echo $_forumrow_val['FORUM_FOLDER_IMG']; ?></div>
			<div class="row1">
				<?php if ($_forumrow_val['FORUM_IMAGE']) {  ?>
					<div style="float: <?php echo (isset($this->_rootref['S_CONTENT_FLOW_BEGIN'])) ? $this->_rootref['S_CONTENT_FLOW_BEGIN'] : ''; ?>; margin-<?php echo (isset($this->_rootref['S_CONTENT_FLOW_END'])) ? $this->_rootref['S_CONTENT_FLOW_END'] : ''; ?>: 5px;"><?php echo $_forumrow_val['FORUM_IMAGE']; ?></div><div style="float: <?php echo (isset($this->_rootref['S_CONTENT_FLOW_BEGIN'])) ? $this->_rootref['S_CONTENT_FLOW_BEGIN'] : ''; ?>;">
				<?php } ?><a class="forumlink" href="<?php echo $_forumrow_val['U_VIEWFORUM']; ?>"><?php echo $_forumrow_val['FORUM_NAME']; ?></a><p class="forumdesc"><?php echo $_forumrow_val['FORUM_DESC']; ?></p><?php if ($_forumrow_val['FORUM_IMAGE']) {  ?></div><?php } ?>
			</div>
			<?php if ($_forumrow_val['CLICKS']) {  ?>
				<td class="row2" colspan="3" align="center"><span class="genmed"><?php echo ((isset($this->_rootref['L_REDIRECTS'])) ? $this->_rootref['L_REDIRECTS'] : ((isset($user->lang['REDIRECTS'])) ? $user->lang['REDIRECTS'] : '{ REDIRECTS }')); ?>: <?php echo $_forumrow_val['CLICKS']; ?></span></td>
			<?php } else { ?>
				<td class="row2" colspan="3" align="center">&nbsp;</td>
			<?php } ?>
		</tr>
	<?php } else { if ($_forumrow_val['S_NO_CAT']) {  ?>
			<tr>
				<td class="cat" colspan="2"><h4><?php echo ((isset($this->_rootref['L_FORUM'])) ? $this->_rootref['L_FORUM'] : ((isset($user->lang['FORUM'])) ? $user->lang['FORUM'] : '{ FORUM }')); ?></h4></td>
				<td class="catdiv" colspan="3">&nbsp;</td>
			</tr>
		<?php } ?>	

<div style="float:left;width:99%;align:center;margin:0;padding:0;background-color:#f0f2f8;margin-left:10px;">
<div style="background-image:url(../images/border_ml.gif);background-repeat:repeat y;width:5px;float:left;margin-left:-7px;height:44px;padding:0;margin-top:-1px;"></div>	
		<div class="row1" style="float:left;width:35px;"><?php echo $_forumrow_val['FORUM_FOLDER_IMG']; ?></div>
			<div class="row1" style="float:left;margin:0;padding:0;width:520px;">
				<?php if ($_forumrow_val['FORUM_IMAGE']) {  ?>
					<div style="float: <?php echo (isset($this->_rootref['S_CONTENT_FLOW_BEGIN'])) ? $this->_rootref['S_CONTENT_FLOW_BEGIN'] : ''; ?>; margin-<?php echo (isset($this->_rootref['S_CONTENT_FLOW_END'])) ? $this->_rootref['S_CONTENT_FLOW_END'] : ''; ?>: 5px;"><?php echo $_forumrow_val['FORUM_IMAGE']; ?></div><div style="float: <?php echo (isset($this->_rootref['S_CONTENT_FLOW_BEGIN'])) ? $this->_rootref['S_CONTENT_FLOW_BEGIN'] : ''; ?>;">
				<?php } ?>
				<a class="forumlink" href="<?php echo $_forumrow_val['U_VIEWFORUM']; ?>"><?php echo $_forumrow_val['FORUM_NAME']; ?></a><p class="forumdesc"><?php echo $_forumrow_val['FORUM_DESC']; ?></p>
				<?php if ($_forumrow_val['MODERATORS']) {  ?>
					<p class="forumdesc"><strong><?php echo $_forumrow_val['L_MODERATOR_STR']; ?>:</strong> <?php echo $_forumrow_val['MODERATORS']; ?></p>
				<?php } if ($_forumrow_val['SUBFORUMS'] && $_forumrow_val['S_LIST_SUBFORUMS']) {  ?>
					<p class="forumdesc"><strong><?php echo $_forumrow_val['L_SUBFORUM_STR']; ?></strong> <?php echo $_forumrow_val['SUBFORUMS']; ?></p>
				<?php } if ($_forumrow_val['FORUM_IMAGE']) {  ?></div><?php } ?>
			</div>
			<div class="row2" style="float:left;width:40px;margin:0;padding:0;"><p class="topicdetails"><?php echo $_forumrow_val['TOPICS']; ?></p></div>
			<div class="row2" style="float:left;margin:0;padding:0;width:40px;"><p class="topicdetails"><?php echo $_forumrow_val['POSTS']; ?></p></div>
			<div class="row2" nowrap="nowrap" style="margin:0;padding:0;float:left;">
				<?php if ($_forumrow_val['LAST_POST_TIME']) {  if ($_forumrow_val['LAST_POST_LINK']) {  ?>
					<p class="topicdetails"><i><?php echo $_forumrow_val['LAST_POST_LINK']; ?></i></p>
					<?php } ?>
					<p class="topicdetails"><?php echo $_forumrow_val['LAST_POST_TIME']; ?></p>
					<p class="topicdetails"><?php echo $_forumrow_val['LAST_POSTER_FULL']; ?>
						<a href="<?php echo $_forumrow_val['U_LAST_POST']; ?>"><?php echo (isset($this->_rootref['LAST_POST_IMG'])) ? $this->_rootref['LAST_POST_IMG'] : ''; ?></a>
					</p>
				<?php } else { ?>
					<p class="topicdetails"><?php echo ((isset($this->_rootref['L_NO_POSTS'])) ? $this->_rootref['L_NO_POSTS'] : ((isset($user->lang['NO_POSTS'])) ? $user->lang['NO_POSTS'] : '{ NO_POSTS }')); ?></p>
				<?php } ?>
			</div>
		</div>
	<?php } } } else { ?>
	<div>
			<div class="row1" colspan="5" align="center"><p class="gensmall"><?php echo ((isset($this->_rootref['L_NO_FORUMS'])) ? $this->_rootref['L_NO_FORUMS'] : ((isset($user->lang['NO_FORUMS'])) ? $user->lang['NO_FORUMS'] : '{ NO_FORUMS }')); ?></p></div>
	</div>
<?php } ?>

<div style="width:100%;float:left;background-color:white;margin:0;padding:0;">
<div style="background-image:url(../images/border_bg.gif);background-repeat:no-repeat;width:20px;float:left;height:12px;"></div>
<div style="width:79%;float:left;background-image:url(../images/border_bm.gif);height:12px;"></div>
<div style="width:140px;float:left;background-image:url(../images/border_bd.gif);background-repeat:no-repeat;height:12px;"></div>
</div>