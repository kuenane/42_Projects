DROP TABLE IF EXISTS `t_article`;
CREATE TABLE `t_article`
(
art_id integer not null primary key auto_increment,
art_title varchar(100) not null,
art_content varchar(2000) not null,
art_prev varchar(2000) not null,
art_subj varchar(2000) not null
) engine=innodb character set utf8 collate utf8_unicode_ci;

DROP TABLE IF EXISTS `t_user`;
CREATE TABLE `t_user`
(
	usr_id integer not null primary key auto_increment,
	usr_name varchar(50) not null,
	usr_password varchar(88) not null,
	usr_salt varchar(23) not null,
	usr_role varchar(50) not null 
)	engine=innodb character set utf8 collate utf8_unicode_ci;

DROP TABLE IF EXISTS `t_comment`;
CREATE TABLE t_comment (
    com_id integer not null primary key auto_increment,
    com_content varchar(500) not null,
    art_id integer not null,
    usr_id integer not null,
    constraint fk_com_art foreign key(art_id) references t_article(art_id),
    constraint fk_com_usr foreign key(usr_id) references t_user(usr_id)
) engine=innodb character set utf8 collate utf8_unicode_ci;
