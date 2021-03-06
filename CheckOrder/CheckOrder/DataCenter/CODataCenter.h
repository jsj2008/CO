//
//  CODataCenter.h
//  CheckOrder
//
//  Created by baojuan on 15/5/22.
//  Copyright (c) 2015年 baojuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "COOrderModel.h"

typedef NS_ENUM(short, COOrderCoinType)
{
    COOrderCoinTypeYours = 0,
    COOrderCoinTypeMine = 1,
};

//statistics
extern NSString * const kCOMonthCost;
extern NSString * const kCODate;
extern NSString * const kCOMyMonthCost;
extern NSString * const kCOTaMonthCost;
extern NSString * const kCOOurMonthCost;
extern NSString * const kCOOurMonthLast;


//statistics
extern NSString * const kCOMonthLast;
extern NSString * const kCOMonthAllCost;




@interface COAPPSetting : NSObject
@property (nonatomic, assign) COOrderCoinType coinToWho;
@property (nonatomic, copy) NSString * taName;
@property (nonatomic, copy) NSString * myName;
@property (nonatomic, assign) float taOriginMoney;
@property (nonatomic, assign) float myOriginMoney;

@end


@interface CODataCenter : NSObject

+ (BOOL)isFirstOpenApp;
+ (void)firstOpenApp;

+ (void)settingApp:(COAPPSetting *)setting;

+ (COOrderCoinType)coinToWho;
+ (float)taSumMoney;
+ (float)mySumMoney;

+ (NSString *)taName;
+ (NSString *)myName;

+ (void)changeMySumMoney:(float)money;
+ (void)changeTaSumMoney:(float)money;

//计算一笔账单每人该付多少钱
+ (float)taShouldPay:(float)orderMoney;
+ (float)meShouldPay:(float)orderMoney;

//消费统计
+ (void)calculationMonthCost;

//计算当月剩余钱数
+ (void)calculationMonthLast;
//更改某账单后update剩余钱数
+ (void)updateMonthLast:(COOrderModel *)model;

/**
 *  获取当前月份剩余钱数
 *
 *  @param month
 *
 *  @return
 */
+ (float)getMonthLast:(NSString *)month;

@end
