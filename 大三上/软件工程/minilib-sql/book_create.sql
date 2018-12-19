/***********************************************************
*													
*														
*	项目名称：	小型图书资料管理系统					
*	子系统名：			
*	功能名称：	
*	完成人员：					
*	完成时间：					
*								
*									
************************************************************/

SET FOREIGN_KEY_CHECKS = 0;

/** 建立数据库book **/
CREATE DATABASE IF NOT EXISTS `Book` CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `Book`;

/** 1、建立图书类型码表 code_booktype **/
DROP TABLE IF EXISTS `Book`.`code_booktype`;
CREATE TABLE `Book`.`code_booktype` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(100)    NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 2、建立部门码表 code_department **/
DROP TABLE IF EXISTS `Book`.`code_department`;
CREATE TABLE `Book`.`code_department` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(100)    NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 3、罚款理由码表 code_penalty **/
DROP TABLE IF EXISTS `Book`.`code_penalty`;
CREATE TABLE `Book`.`code_penalty` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(100)    NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 4、建立出版社表/代码表 code_press **/
DROP TABLE IF EXISTS `Book`.`code_press`;
CREATE TABLE `Book`.`code_press` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(100)    NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    `zipcode`   varchar(10)     DEFAULT NULL    COMMENT '邮政编码',
    `address`   varchar(200)    DEFAULT NULL    COMMENT '通信地址',
    `homepage`  varchar(100)    DEFAULT NULL    COMMENT '主页地址',
    `contact`   varchar(20)     DEFAULT NULL    COMMENT '联系人员',
    `telephone` varchar(20)     DEFAULT NULL    COMMENT '固定电话',
    `mobile`    varchar(20)     DEFAULT NULL    COMMENT '移动电话',
    `fax`       varchar(20)     DEFAULT NULL    COMMENT '传真号码',
    `email`     varchar(50)     DEFAULT NULL    COMMENT '电子邮件',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 5、建立性别类型码表 code_sex **/
DROP TABLE IF EXISTS `Book`.`code_sex`;
CREATE TABLE `Book`.`code_sex` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(100)    NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 6、建立图书开本代码表 code_sizes **/
DROP TABLE IF EXISTS `Book`.`code_sizes`;
CREATE TABLE `Book`.`code_sizes` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(50)     NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 7、建立用户类型代码表 code_usertype **/
DROP TABLE IF EXISTS `Book`.`code_usertype`;
CREATE TABLE `Book`.`code_usertype` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(50)     NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    `numbers`   int(10)         DEFAULT NULL    COMMENT '借书数量',
    `days`      int(10)         DEFAULT NULL    COMMENT '借阅天数',
    `renewtimes`int(2)          DEFAULT 2       COMMENT '续借次数',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 8、建立图书版本代码表 code_version **/
DROP TABLE IF EXISTS `Book`.`code_version`;
CREATE TABLE `Book`.`code_version` (
    `codeid`    varchar(20)     NOT NULL        COMMENT '信息编码',
    `codename`  varchar(50)     NOT NULL        COMMENT '信息内容',
    `codetype`  varchar(4)      DEFAULT NULL    COMMENT '结点类型',
    PRIMARY KEY (`codeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 9、预约图书表 t_appointment **/
DROP TABLE IF EXISTS `Book`.`T_Appointment`;
CREATE TABLE `Book`.`t_appointment` (
    `id`        int(10)         NOT NULL AUTO_INCREMENT COMMENT '自动编号',
    `userid`    int(10)         NOT NULL                COMMENT '用户编号',
    `bookid`    int(10)         NOT NULL                COMMENT '图书编号',
    `aptdate`   datetime        DEFAULT NULL            COMMENT '预约时间',
    `status`    tinyint(1)      DEFAULT 0               COMMENT '预约状态',
    `notes`     text            DEFAULT NULL            COMMENT '备注信息',
    PRIMARY KEY (`id`) ,
    INDEX `FK_t_appointment_1` (`userid` ASC) ,
    INDEX `FK_t_appointment_2` (`bookid` ASC) ,
    CONSTRAINT `FK_t_appointment_1`
        FOREIGN KEY (`userid` )
        REFERENCES `book`.`t_user` (`userid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_appointment_2`
        FOREIGN KEY (`bookid` )
        REFERENCES `book`.`t_book` (`bookid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 10、图书主表  t_book **/
DROP TABLE IF EXISTS `Book`.`T_Book`;
CREATE  TABLE `book`.`t_book` (
    `bookid`        INT(10)         NOT NULL AUTO_INCREMENT COMMENT '自动编号' ,
    `typeid`        VARCHAR(20)     DEFAULT NULL            COMMENT '图书类型',
    `isbn`          VARCHAR(20)     DEFAULT NULL            COMMENT '图书编号',
    `placeid`       VARCHAR(20)     DEFAULT NULL            COMMENT '上架编号',
    `title`         VARCHAR(100)    DEFAULT NULL            COMMENT '图书名称',
    `authors`       VARCHAR(50)     DEFAULT NULL            COMMENT '图书作者',
    `translators`   VARCHAR(50)     DEFAULT NULL            COMMENT '翻译人员',
    `pressid`       VARCHAR(20)     DEFAULT NULL            COMMENT '出版社号',
    `pages`         INT(10)         DEFAULT NULL            COMMENT '图书页数',
    `sizesid`       VARCHAR(20)     DEFAULT NULL            COMMENT '图书开本',
    `pubdate`       DATETIME        DEFAULT NULL            COMMENT '出版日期',
    `versionid`     VARCHAR(20)     DEFAULT NULL            COMMENT '版本编号',
    `price`         DECIMAL(19,4)   DEFAULT NULL            COMMENT '图书价格',
    `amount`        INT(10)         DEFAULT NULL            COMMENT '入库数量',
    `current`       INT(10)         DEFAULT NULL            COMMENT '当前数量',
    `url`           VARCHAR(50)     DEFAULT NULL            COMMENT '资源链接',
    `disk`          VARCHAR(50)     DEFAULT NULL            COMMENT '资源光盘',
    `adddate`       DATETIME        DEFAULT NULL            COMMENT '入库时间',
    `status`        TINYINT(1)      DEFAULT NULL            COMMENT '图书状态',
    `contents`      LONGTEXT        DEFAULT NULL            COMMENT '内容简介',
    `notes`         TEXT            DEFAULT NULL            COMMENT '备注信息',
    `image`         LONGBLOB        DEFAULT NULL            COMMENT '封页图片',
    `clazz`         tinyint(1)      DEFAULT 0               COMMENT '图书级别',
    PRIMARY KEY (`bookid`) ,
    INDEX `FK_t_book_1` (`typeid`       ASC) ,
    INDEX `FK_t_book_2` (`pressid`      ASC) ,
    INDEX `FK_t_book_3` (`sizesid`      ASC) ,
    INDEX `FK_t_book_4` (`versionid`    ASC) ,
    CONSTRAINT `FK_t_book_1`
        FOREIGN KEY (`typeid` )
        REFERENCES `book`.`code_booktype` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_book_2`
        FOREIGN KEY (`pressid` )
        REFERENCES `book`.`code_press` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_book_3`
        FOREIGN KEY (`sizesid` )
        REFERENCES `book`.`code_sizes` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_book_4`
        FOREIGN KEY (`versionid` )
        REFERENCES `book`.`code_version` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION
)ENGINE = InnoDB DEFAULT CHARACTER SET = utf8;


/** 11、罚款记账表 t_penalty **/
DROP TABLE IF EXISTS `Book`.`T_Penalty`;
CREATE TABLE `Book`.`t_penalty` (
    `id`        int(10)         NOT NULL AUTO_INCREMENT COMMENT '自动编号',
    `userid`    int(10)         NOT NULL                COMMENT '用户编号',
    `reasonid`  VARCHAR(20)     NOT NULL                COMMENT '罚款理由',
    `money`     DECIMAL(19,4)   DEFAULT NULL            COMMENT '罚款金额',
    `adddate`   datetime        DEFAULT NULL            COMMENT '罚款日期',
    `status`    tinyint(1)      DEFAULT 0               COMMENT '当前状态',
    `notes`     text            DEFAULT NULL            COMMENT '备注信息',
    PRIMARY KEY (`id`) ,
    INDEX `FK_t_penalty_1` (`userid`    ASC) ,
    INDEX `FK_t_penalty_2` (`reasonid`  ASC) ,
    CONSTRAINT `FK_t_penalty_1`
        FOREIGN KEY (`userid` )
        REFERENCES `book`.`t_user` (`userid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_penalty_2`
        FOREIGN KEY (`reasonid` )
        REFERENCES `book`.`code_penalty` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 12、借还书登记表  t_record **/
DROP TABLE IF EXISTS `Book`.`T_Record`;
CREATE TABLE `Book`.`t_record` (
    `id`            int(10)     NOT NULL AUTO_INCREMENT COMMENT '自动编号',
    `userid`        int(10)     NOT NULL                COMMENT '用户编号',
    `bookid`        int(10)     NOT NULL                COMMENT '图书编号',
    `borrowdate`    datetime    DEFAULT NULL            COMMENT '借书日期',
    `returndate`    datetime    DEFAULT NULL            COMMENT '还书日期',
    `renewtimes`    tinyint(1)  DEFAULT 0               COMMENT '续借次数',
    `notes`         text        DEFAULT NULL            COMMENT '备注信息',
    PRIMARY KEY (`id`) ,
    INDEX `FK_t_record_1` (`userid` ASC) ,
    INDEX `FK_t_record_2` (`bookid` ASC) ,
    CONSTRAINT `FK_t_record_1`
        FOREIGN KEY (`userid` )
        REFERENCES `book`.`t_user` (`userid`)
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_record_2`
        FOREIGN KEY (`bookid` )
        REFERENCES `book`.`t_book` (`bookid`)
        ON DELETE NO ACTION
        ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/** 13、订阅图书登记表  t_subscribe **/
DROP TABLE IF EXISTS `Book`.`T_Subscribe`;
CREATE TABLE `Book`.`t_subscribe` (
    `id`        int(10)         NOT NULL AUTO_INCREMENT COMMENT '自动编号',
    `userid`    int(10)         NOT NULL                COMMENT '用户编号',
    `title`     varchar(100)    DEFAULT NULL            COMMENT '图书名称',
    `authors`   varchar(200)    DEFAULT NULL            COMMENT '图书作者',
    `pressid`   varchar(20)     DEFAULT NULL            COMMENT '出版社号',
    `isbn`      varchar(20)     DEFAULT NULL            COMMENT '图书编号',
    `quantity`  int(3)          DEFAULT NULL            COMMENT '订购数量',
    `price`     double          DEFAULT NULL            COMMENT '图书价格',
    `subdate`   datetime        DEFAULT NULL            COMMENT '订购日期',
    `notes`     text            DEFAULT NULL            COMMENT '备注信息',
    PRIMARY KEY (`id`) ,
    INDEX `FK_t_subscribe_1`  (`userid`   ASC) ,
    INDEX `FK_t_subscribe_2`  (`pressid`  ASC) ,
    CONSTRAINT `FK_t_subscribe_1`
        FOREIGN KEY (`userid` )
        REFERENCES `book`.`t_user` (`userid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_subscribe_2`
        FOREIGN KEY (`pressid` )
        REFERENCES `book`.`code_press` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


/** 14、用户主表  t_record **/
DROP TABLE IF EXISTS `Book`.`T_User`;
CREATE TABLE `Book`.`t_user` (
    `userid`    int(10)     NOT NULL AUTO_INCREMENT COMMENT '自动编号',
    `idcard`    varchar(20) DEFAULT NULL            COMMENT '证件号码',
    `name`      varchar(20) DEFAULT NULL            COMMENT '用户姓名',
    `sexid`     varchar(20) NOT NULL                COMMENT '性别编号',
    `birthday`  varchar(20) DEFAULT NULL            COMMENT '用户生日',
    `deptid`    varchar(20) NOT NULL                COMMENT '单位编号',
    `regdate`   varchar(20) DEFAULT NULL            COMMENT '注册日期',
    `typeid`    varchar(20) NOT NULL                COMMENT '用户类型',
    `account`   varchar(20) DEFAULT NULL            COMMENT '用户账户',
    `password`  varchar(20) DEFAULT NULL            COMMENT '账户密码',
    `notes`     text        DEFAULT NULL            COMMENT '备注信息',
    PRIMARY KEY (`userid`) ,
    INDEX `FK_t_user_1` (`sexid`    ASC) ,
    INDEX `FK_t_user_2` (`deptid`   ASC) ,
    INDEX `FK_t_user_3` (`typeid`   ASC) ,
    CONSTRAINT `FK_t_user_1`
        FOREIGN KEY (`sexid` )
        REFERENCES `book`.`code_sex` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_user_2`
        FOREIGN KEY (`deptid` )
        REFERENCES `book`.`code_department` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION,
    CONSTRAINT `FK_t_user_3`
        FOREIGN KEY (`typeid` )
        REFERENCES `book`.`code_usertype` (`codeid` )
        ON DELETE NO ACTION
        ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

commit;

