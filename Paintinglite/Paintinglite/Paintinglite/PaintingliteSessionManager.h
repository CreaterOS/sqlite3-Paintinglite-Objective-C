//
//  PaintingliteSessionManager.h
//  Paintinglite
//
//  Created by Bryant Reyn on 2020/5/26.
//  Copyright © 2020 Bryant Reyn. All rights reserved.
//

/**
 * PaintingliteSessionManager
 * 创建一个Session管理者
 * 连接数据库
 */

#import <Foundation/Foundation.h>
#import "PaintingliteSessionError.h"
#import "PaintingliteDataBaseOptions.h"
#import "PaintingliteTableOptions.h"
#import "PaintingliteLog.h"

NS_ASSUME_NONNULL_BEGIN

@interface PaintingliteSessionManager : NSObject

/* 单例模式 */
+ (instancetype)sharePaintingliteSessionManager;

/**
 * 连接数据库
 * 数据库的名称
 */
- (Boolean)openSqlite:(NSString *)fileName;

/**
 * 连接数据库
 * 数据库的名称
 * 连接完成的Block操作
 */

- (Boolean)openSqlite:(NSString *)fileName completeHandler:(void(^)(NSString *filePath,PaintingliteSessionError *error,Boolean success))completeHandler;

/**
 * 获得数据库
 */
- (sqlite3 *)getSqlite3;

/**
 * 释放数据库
 */
- (Boolean)releaseSqlite;

- (Boolean)releaseSqliteCompleteHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;

/**
 * 删除日志文件
 */
- (void)removeLogFile:(NSString *)fileName;

/**
 * 读取日志文件
 */
- (NSString *)readLogFile:(NSString *__nonnull)fileName;

- (NSString *)readLogFile:(NSString *)fileName dateTime:(NSDate *__nonnull)dateTime;

- (NSString *)readLogFile:(NSString *)fileName logStatus:(PaintingliteLogStatus)logStatus;

/**
 * 创建表
 */
- (Boolean)createTableForSQL:(NSString *)sql;
- (Boolean)createTableForSQL:(NSString *)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (Boolean)createTableForName:(NSString *)tableName content:(NSString *)content;
- (Boolean)createTableForName:(NSString *)tableName content:(NSString *)content completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (Boolean)createTableForObj:(id)obj createStyle:(PaintingliteDataBaseOptionsCreateStyle)createStyle;
- (Boolean)createTableForObj:(id)obj createStyle:(PaintingliteDataBaseOptionsCreateStyle)createStyle completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;

/**
 * 更新表
 */
- (BOOL)alterTableForSQL:(NSString *)sql;
- (BOOL)alterTableForSQL:(NSString *)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (BOOL)alterTableForName:(NSString *__nonnull)oldName newName:(NSString *__nonnull)newName;
- (BOOL)alterTableForName:(NSString *__nonnull)oldName newName:(NSString *__nonnull)newName completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (BOOL)alterTableAddColumn:(NSString *)tableName columnName:(NSString *__nonnull)columnName columnType:(NSString *__nonnull)columnType;
- (BOOL)alterTableAddColumn:(NSString *)tableName columnName:(NSString *__nonnull)columnName columnType:(NSString *__nonnull)columnType completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (BOOL)alterTableForObj:(id)obj;
- (BOOL)alterTableForObj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;

/**
 * 删除表
 */
- (Boolean)dropTableForSQL:(NSString *)sql;
- (Boolean)dropTableForSQL:(NSString *)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (Boolean)dropTableForTableName:(NSString *)tableName;
- (Boolean)dropTableForTableName:(NSString *)tableName completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;
- (Boolean)dropTableForObj:(id)obj;
- (Boolean)dropTableForObj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success))completeHandler;

/**
 * 查看数据
 */
- (NSMutableArray *)execQuerySQL:(NSString *__nonnull)sql;
- (Boolean)execQuerySQL:(NSString *__nonnull)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray))completeHandler;
- (id)execQuerySQL:(NSString *__nonnull)sql obj:(id)obj;
- (Boolean)execQuerySQL:(NSString *__nonnull)sql obj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id> *resObjList))completeHandler;

- (void)execQuerySQLPrepareStatementSql:(NSString *__nonnull)prepareStatementSql;

- (void)setPrepareStatementSqlParameter:(NSUInteger)index paramter:(NSString *__nonnull)paramter;

- (void)setPrepareStatementSqlParameter:(NSArray *__nonnull)paramter;

- (NSMutableArray *)execPrepareStatementSql;
- (Boolean)execPrepareStatementSqlCompleteHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray))completeHandler;

- (id)execPrepareStatementSqlWithObj:(id)obj;
- (Boolean)execPrepareStatementSqlWithObj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (NSMutableArray *)execLikeQuerySQLWithTableName:(NSString *__nonnull)tableName field:(NSString *__nonnull)field like:(NSString *__nonnull)like;
- (Boolean)execLikeQuerySQLWithTableName:(NSString *__nonnull)tableName field:(NSString *__nonnull)field like:(NSString *__nonnull)like completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray))completeHandler;

- (id)execLikeQuerySQLWithField:(NSString *__nonnull)field like:(NSString *__nonnull)like obj:(id)obj;
- (Boolean)execLikeQuerySQLWithField:(NSString *__nonnull)field like:(NSString *__nonnull)like obj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (NSMutableArray *)execLimitQuerySQLWithTableName:(NSString *__nonnull)tableName limitStart:(NSUInteger)start limitEnd:(NSUInteger)end;
- (Boolean)execLimitQuerySQLWithTableName:(NSString *__nonnull)tableName limitStart:(NSUInteger)start limitEnd:(NSUInteger)end completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray))completeHandler;

- (id)execLimitQuerySQLWithLimitStart:(NSUInteger)start limitEnd:(NSUInteger)end obj:(id)obj;
- (Boolean)execLimitQuerySQLWithLimitStart:(NSUInteger)start limitEnd:(NSUInteger)end obj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (NSMutableArray *)execOrderByQuerySQLWithTableName:(NSString *__nonnull)tableName orderbyContext:(NSString *__nonnull)orderbyContext orderStyle:(PaintingliteOrderByStyle)orderStyle;
- (Boolean)execOrderByQuerySQLWithTableName:(NSString *__nonnull)tableName orderbyContext:(NSString *__nonnull)orderbyContext orderStyle:(PaintingliteOrderByStyle)orderStyle completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray))completeHandler;

- (id)execOrderByQuerySQLWithOrderbyContext:(NSString *__nonnull)orderbyContext orderStyle:(PaintingliteOrderByStyle)orderStyle obj:(id)obj;
- (Boolean)execOrderByQuerySQLWithOrderbyContext:(NSString *__nonnull)orderbyContext orderStyle:(PaintingliteOrderByStyle)orderStyle obj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

#pragma mark - PQL查询
- (id)execQueryPQL:(NSString *__nonnull)pql;
- (Boolean)execQueryPQL:(NSString *__nonnull)pql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (id)execPrepareStatementPQL;
- (Boolean)execPrepareStatementPQLWithCompleteHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (void)execQueryPQLPrepareStatementPQL:(NSString *__nonnull)prepareStatementPQL;
- (void)setPrepareStatementPQLParameter:(NSUInteger)index paramter:(NSString *__nonnull)paramter;
- (void)setPrepareStatementPQLParameter:(NSArray *__nonnull)paramter;

- (id)execLikeQueryPQL:(NSString *__nonnull)pql;
- (Boolean)execLikeQueryPQL:(NSString *__nonnull)pql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (id)execLimitQueryPQL:(NSString *__nonnull)pql;
- (Boolean)execLimitQueryPQL:(NSString *__nonnull)pql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (id)execOrderQueryPQL:(NSString *__nonnull)pql;
- (Boolean)execOrderQueryPQL:(NSString *__nonnull)pql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

- (id)execPQL:(NSString *__nonnull)pql;
- (Boolean)execPQL:(NSString *__nonnull)pql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray *resArray,NSMutableArray<id>* resObjList))completeHandler;

#pragma mark - CUD
/* 增加数据 */
- (Boolean)insert:(NSString *__nonnull)sql;
- (Boolean)insert:(NSString *__nonnull)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray<id> *newList))completeHandler;
- (Boolean)insertWithObj:(id)obj completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray<id> *newList))completeHandler;

/* 更新数据 */
- (Boolean)update:(NSString *__nonnull)sql;
- (Boolean)update:(NSString *__nonnull)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray<id> *newList))completeHandler;
- (Boolean)updateWithObj:(id)obj condition:(NSString *__nonnull)condition completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray<id> *newList))completeHandler;

/* 删除数据 */
- (Boolean)del:(NSString *__nonnull)sql;
- (Boolean)del:(NSString *__nonnull)sql completeHandler:(void(^)(PaintingliteSessionError *error,Boolean success,NSMutableArray<id> *newList))completeHandler;

@end

NS_ASSUME_NONNULL_END
