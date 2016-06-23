#ifndef _AK449x_H_
#define _AK449x_H_
    
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
    
#include <SPI.h>
#include <Wire.h>
#define CSELECT_MAX 10
#define CHIPNUM_MAX 4
#define REGADDR 10
#define REGNUM 8
#define BIT_HIGH 1
#define BIT_LOW 0
#define VAL_WRITE BIT_HIGH
#define VAL_READ BIT_LOW
#define VERITA9x_CHIP0 0
#define VERITA9x_CHIP1 1
#define VERITA9x_CHIP2 2
#define VERITA9x_CHIP3 3
#define VERITA9x_REG_CTRL1 0 //00H
#define VERITA9x_00RSTN 0 //00H, 0
#define VERITA9x_00RSTN_init BIT_LOW //00H, 0, LOW
#define VERITA9x_01DIF0 1 //00H, 1
#define VERITA9x_01DIF0_init BIT_LOW //00H, 1, LOW
#define VERITA9x_02DIF1 2 //00H, 2
#define VERITA9x_02DIF1_init BIT_HIGH //00H, 2, HIGH
#define VERITA9x_03DIF2 3 //00H, 3
#define VERITA9x_03DIF2_init BIT_LOW //00H, 3, LOW
#define VERITA9x_04RSVD 4 //00H, 4
#define VERITA9x_04RSVD_init BIT_LOW //00H, 4, LOW
#define VERITA9x_05ECS 5 //00H, 5
#define VERITA9x_05ECS_init BIT_LOW //00H, 5, LOW
#define VERITA9x_06EXDF 6 //00H, 6
#define VERITA9x_06EXDF_init BIT_LOW //00H, 6, LOW
#define VERITA9x_07ACKS 7 //00H, 7
#define VERITA9x_07ACKS_init BIT_LOW //00H, 7, LOW
#define VERITA9x_REG_CTRL2 1 //01H
#define VERITA9x_10SMUTE 0 //01H, 0
#define VERITA9x_10SMUTE_init BIT_LOW //01H, 0, LOW
#define VERITA9x_11DEM0 1 //01H, 1
#define VERITA9x_11DEM0_init BIT_HIGH //01H, 1, HIGH
#define VERITA9x_12DEM1 2 //01H, 2
#define VERITA9x_12DEM1_init BIT_LOW //01H, 2, LOW
#define VERITA9x_13DFS0 3 //01H, 3
#define VERITA9x_13DFS0_init BIT_LOW //01H, 3, LOW
#define VERITA9x_14DFS1 4 //01H, 4
#define VERITA9x_14DFS1_init BIT_LOW //01H, 4, LOW
#define VERITA9x_15SD 5 //01H, 5
#define VERITA9x_15SD_init BIT_HIGH //01H, 5, HIGH
#define VERITA9x_16DZFM 6 //01H, 6
#define VERITA9x_16DZFM_init BIT_LOW //01H, 6, LOW
#define VERITA9x_17DZFE 7 //01H, 7
#define VERITA9x_17DZFE_init BIT_LOW //01H, 7, LOW
#define VERITA9x_REG_CTRL3 2 //02H
#define VERITA9x_20SLOW 0 //02H, 0
#define VERITA9x_20SLOW_init BIT_LOW //02H, 0, LOW
#define VERITA9x_21SELLR 1 //02H, 1
#define VERITA9x_21SELLR_init BIT_LOW //02H, 1, LOW
#define VERITA9x_22DZFB 2 //02H, 2
#define VERITA9x_22DZFB_init BIT_LOW //02H, 2, LOW
#define VERITA9x_23MONO 3 //02H, 3
#define VERITA9x_23MONO_init BIT_LOW //02H, 3, LOW
#define VERITA9x_24DCKB 4 //02H, 4
#define VERITA9x_24DCKB_init BIT_LOW //02H, 4, LOW
#define VERITA9x_25DCKS 5 //02H, 5
#define VERITA9x_25DCKS_init BIT_LOW //02H, 5, LOW
#define VERITA9x_26RSVD 6 //02H, 6
#define VERITA9x_26RSVD_init BIT_LOW //02H, 6, LOW
#define VERITA9x_27DP 7 //02H, 7
#define VERITA9x_27DP_init BIT_LOW //02H, 7, LOW
#define VERITA9x_REG_LATT 3 //03H
#define VERITA9x_30LATT0 0 //03H, 0
#define VERITA9x_30LATT0_init BIT_HIGH //03H, 0, HIGH
#define VERITA9x_31LATT1 1 //03H, 1
#define VERITA9x_31LATT1_init BIT_HIGH //03H, 1, HIGH
#define VERITA9x_32LATT2 2 //03H, 2
#define VERITA9x_32LATT2_init BIT_HIGH //03H, 2, HIGH
#define VERITA9x_33LATT3 3 //03H, 3
#define VERITA9x_33LATT3_init BIT_HIGH //03H, 3, HIGH
#define VERITA9x_34LATT4 4 //03H, 4
#define VERITA9x_34LATT4_init BIT_HIGH //03H, 4, HIGH
#define VERITA9x_35LATT5 5 //03H, 5
#define VERITA9x_35LATT5_init BIT_HIGH //03H, 5, HIGH
#define VERITA9x_36LATT6 6 //03H, 6
#define VERITA9x_36LATT6_init BIT_HIGH //03H, 6, HIGH
#define VERITA9x_37LATT7 7 //03H, 7
#define VERITA9x_37LATT7_init BIT_HIGH //03H, 7, HIGH
#define VERITA9x_REG_RATT 4 //04H
#define VERITA9x_40RATT0 0 //04H, 0
#define VERITA9x_40RATT0_init BIT_HIGH //04H, 0, HIGH
#define VERITA9x_41RATT1 1 //04H, 1
#define VERITA9x_41RATT1_init BIT_HIGH //04H, 1, HIGH
#define VERITA9x_42RATT2 2 //04H, 2
#define VERITA9x_42RATT2_init BIT_HIGH //04H, 2, HIGH
#define VERITA9x_43RATT3 3 //04H, 3
#define VERITA9x_43RATT3_init BIT_HIGH //04H, 3, HIGH
#define VERITA9x_44RATT4 4 //04H, 4
#define VERITA9x_44RATT4_init BIT_HIGH //04H, 4, HIGH
#define VERITA9x_45RATT5 5 //04H, 5
#define VERITA9x_45RATT5_init BIT_HIGH //04H, 5, HIGH
#define VERITA9x_46RATT6 6 //04H, 6
#define VERITA9x_46RATT6_init BIT_HIGH //04H, 6, HIGH
#define VERITA9x_47RATT7 7 //04H, 7
#define VERITA9x_47RATT7_init BIT_HIGH //04H, 7, HIGH
#define VERITA9x_REG_CTRL4 5 //05H
#define VERITA9x_50SSLOW 0 //05H, 0
#define VERITA9x_50SSLOW_init BIT_LOW //05H, 0, LOW
#define VERITA9x_51DFS2 1 //05H, 1
#define VERITA9x_51DFS2_init BIT_LOW //05H, 1, LOW
#define VERITA9x_52RSVD 2 //05H, 2
#define VERITA9x_52RSVD_init BIT_LOW //05H, 2, LOW
#define VERITA9x_53RSVD 3 //05H, 3
#define VERITA9x_53RSVD_init BIT_LOW //05H, 3, LOW
#define VERITA9x_54RSVD 4 //05H, 4
#define VERITA9x_54RSVD_init BIT_LOW //05H, 4, LOW
#define VERITA9x_55RSVD 5 //05H, 5
#define VERITA9x_55RSVD_init BIT_LOW //05H, 5, LOW
#define VERITA9x_56INVR 6 //05H, 6
#define VERITA9x_56INVR_init BIT_LOW //05H, 6, LOW
#define VERITA9x_57INVL 7 //05H, 7
#define VERITA9x_57INVL_init BIT_LOW //05H, 7, LOW
#define VERITA90_REG_CTRL5 6 //06H
#define VERITA90_60DSDSEL0 0 //06H, 0
#define VERITA90_60DSDSEL0_init BIT_LOW //06H, 0, LOW
#define VERITA90_61DSDD 1 //06H, 1
#define VERITA90_61DSDD_init BIT_LOW //06H, 1, LOW
#define VERITA90_62RSVD 2 //06H, 2
#define VERITA90_62RSVD_init BIT_LOW //06H, 2, LOW
#define VERITA90_63DMRE 3 //06H, 3
#define VERITA90_63DMRE_init BIT_LOW //06H, 3, LOW
#define VERITA90_64DMC 4 //06H, 4
#define VERITA90_64DMC_init BIT_LOW //06H, 4, LOW
#define VERITA90_65DMR 5 //06H, 5
#define VERITA90_65DMR_init BIT_LOW //06H, 5, LOW
#define VERITA90_66DML 6 //06H, 6
#define VERITA90_66DML_init BIT_LOW //06H, 6, LOW
#define VERITA90_67DDM 7 //06H, 7
#define VERITA90_67DDM_init BIT_LOW //06H, 7, LOW
#define VERITA90_REG_CTRL6 7 //07H
#define VERITA90_70SYNCE 0 //07H, 0
#define VERITA90_70SYNCE_init BIT_LOW //07H, 0, LOW
#define VERITA90_71RSVD 1 //07H, 1
#define VERITA90_71RSVD_init BIT_LOW //07H, 1, LOW
#define VERITA90_72RSVD 2 //07H, 2
#define VERITA90_72RSVD_init BIT_LOW //07H, 2, LOW
#define VERITA90_73RSVD 3 //07H, 3
#define VERITA90_73RSVD_init BIT_LOW //07H, 3, LOW
#define VERITA90_74RSVD 4 //07H, 4
#define VERITA90_74RSVD_init BIT_LOW //07H, 4, LOW
#define VERITA90_75RSVD 5 //07H, 5
#define VERITA90_75RSVD_init BIT_LOW //07H, 5, LOW
#define VERITA90_76RSVD 6 //07H, 6
#define VERITA90_76RSVD_init BIT_LOW //07H, 6, LOW
#define VERITA90_77RSVD 7 //07H, 7
#define VERITA90_77RSVD_init BIT_LOW //07H, 7, LOW
#define VERITA90_REG_CTRL7 8 //08H
#define VERITA90_80SC0 0 //08H, 0
#define VERITA90_80SC0_init BIT_LOW //08H, 0, LOW
#define VERITA90_81SC1 1 //08H, 1
#define VERITA90_81SC1_init BIT_LOW //08H, 1, LOW
#define VERITA90_82RSVD 2 //08H, 2
#define VERITA90_82RSVD_init BIT_LOW //08H, 2, LOW
#define VERITA90_83RSVD 3 //08H, 3
#define VERITA90_83RSVD_init BIT_LOW //08H, 3, LOW
#define VERITA90_84RSVD 4 //08H, 4
#define VERITA90_84RSVD_init BIT_LOW //08H, 4, LOW
#define VERITA90_85RSVD 5 //08H, 5
#define VERITA90_85RSVD_init BIT_LOW //08H, 5, LOW
#define VERITA90_86RSVD 6 //08H, 6
#define VERITA90_86RSVD_init BIT_LOW //08H, 6, LOW
#define VERITA90_87RSVD 7 //08H, 7
#define VERITA90_87RSVD_init BIT_LOW //08H, 7, LOW
#define VERITA90_REG_CTRL8 9 //09H
#define VERITA90_90DSDSEL1 0 //09H, 0
#define VERITA90_90DSDSEL1_init BIT_LOW //09H, 0, LOW
#define VERITA90_91DSDF 1 //09H, 1
#define VERITA90_91DSDF_init BIT_LOW //09H, 1, LOW
#define VERITA90_92RSVD 2 //09H, 2
#define VERITA90_92RSVD_init BIT_LOW //09H, 2, LOW
#define VERITA90_93RSVD 3 //09H, 3
#define VERITA90_93RSVD_init BIT_LOW //09H, 3, LOW
#define VERITA90_94RSVD 4 //09H, 4
#define VERITA90_94RSVD_init BIT_LOW //09H, 4, LOW
#define VERITA90_95RSVD 5 //09H, 5
#define VERITA90_95RSVD_init BIT_LOW //09H, 5, LOW
#define VERITA90_96RSVD 6 //09H, 6
#define VERITA90_96RSVD_init BIT_LOW //09H, 6, LOW
#define VERITA90_97RSVD 7 //09H, 7
#define VERITA90_97RSVD_init BIT_LOW //09H, 7, LOW
#define VERITA95_REG_CTRL5 6 //06H
#define VERITA95_60DSDDSEL 0 //06H, 0
#define VERITA95_60DSDDSEL_init BIT_LOW //06H, 0, LOW
#define VERITA95_61DSDD0 1 //06H, 1
#define VERITA95_61DSDD0_init BIT_LOW //06H, 1, LOW
#define VERITA95_62DSDD1 2 //06H, 2
#define VERITA95_62DSDD1_init BIT_LOW //06H, 2, LOW
#define VERITA95_63DMRE 3 //06H, 3
#define VERITA95_63DMRE_init BIT_LOW //06H, 3, LOW
#define VERITA95_64DMC 4 //06H, 4
#define VERITA95_64DMC_init BIT_LOW //06H, 4, LOW
#define VERITA95_65DMR 5 //06H, 5
#define VERITA95_65DMR_init BIT_LOW //06H, 5, LOW
#define VERITA95_66DML 6 //06H, 6
#define VERITA95_66DML_init BIT_LOW //06H, 6, LOW
#define VERITA95_67DDM 7 //06H, 7
#define VERITA95_67DDM_init BIT_LOW //06H, 7, LOW
#define VERITA95_REG_CTRL6 7 //07H
#define VERITA95_70SYNCE 0 //07H, 0
#define VERITA95_70SYNCE_init BIT_LOW //07H, 0, LOW
#define VERITA95_71RSVD 1 //07H, 1
#define VERITA95_71RSVD_init BIT_LOW //07H, 1, LOW
#define VERITA95_72RSVD 2 //07H, 2
#define VERITA95_72RSVD_init BIT_LOW //07H, 2, LOW
#define VERITA95_73RSVD 3 //07H, 3
#define VERITA95_73RSVD_init BIT_LOW //07H, 3, LOW
#define VERITA95_74RSVD 4 //07H, 4
#define VERITA95_74RSVD_init BIT_LOW //07H, 4, LOW
#define VERITA95_75RSVD 5 //07H, 5
#define VERITA95_75RSVD_init BIT_LOW //07H, 5, LOW
#define VERITA95_76RSVD 6 //07H, 6
#define VERITA95_76RSVD_init BIT_LOW //07H, 6, LOW
#define VERITA95_77RSVD 7 //07H, 7
#define VERITA95_77RSVD_init BIT_LOW //07H, 7, LOW
#define VERITA95_REG_CTRL7 8 //08H
#define VERITA95_80SC0 0 //08H, 0
#define VERITA95_80SC0_init BIT_LOW //08H, 0, LOW
#define VERITA95_81SC1 1 //08H, 1
#define VERITA95_81SC1_init BIT_LOW //08H, 1, LOW
#define VERITA95_82SC2 2 //08H, 2
#define VERITA95_82SC2_init BIT_LOW //08H, 2, LOW
#define VERITA95_83RSVD 3 //08H, 3
#define VERITA95_83RSVD_init BIT_LOW //08H, 3, LOW
#define VERITA95_84RSVD 4 //08H, 4
#define VERITA95_84RSVD_init BIT_LOW //08H, 4, LOW
#define VERITA95_85RSVD 5 //08H, 5
#define VERITA95_85RSVD_init BIT_LOW //08H, 5, LOW
#define VERITA95_86RSVD 6 //08H, 6
#define VERITA95_86RSVD_init BIT_LOW //08H, 6, LOW
#define VERITA95_87RSVD 7 //08H, 7
#define VERITA95_87RSVD_init BIT_LOW //08H, 7, LOW
#define VERITA95_REG_RSVD 9 //09H
#define VERITA95_90DSDSEL1 0 //09H, 0
#define VERITA95_90DSDSEL1_init BIT_LOW //09H, 0, LOW
#define VERITA95_91DSDF 1 //09H, 1
#define VERITA95_91DSDF_init BIT_LOW //09H, 1, LOW
#define VERITA95_92RSVD 2 //09H, 2
#define VERITA95_92RSVD_init BIT_LOW //09H, 2, LOW
#define VERITA95_93RSVD 3 //09H, 3
#define VERITA95_93RSVD_init BIT_LOW //09H, 3, LOW
#define VERITA95_94RSVD 4 //09H, 4
#define VERITA95_94RSVD_init BIT_LOW //09H, 4, LOW
#define VERITA95_95RSVD 5 //09H, 5
#define VERITA95_95RSVD_init BIT_LOW //09H, 5, LOW
#define VERITA95_96RSVD 6 //09H, 6
#define VERITA95_96RSVD_init BIT_LOW //09H, 6, LOW
#define VERITA95_97RSVD 7 //09H, 7
#define VERITA95_97RSVD_init BIT_LOW //09H, 7, LOW
class AK449x{
public:
    void setinit(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum);
    void RSTN(uint8_t ChipSelect, uint8_t ChipNum);
    void DIF(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode, boolean SendNow);
    void ECS(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void EXDF(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void ACKS(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void SMUTE(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DEM(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode, boolean SendNow);
    void DFS(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode, boolean SendNow);
    void SD(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode, boolean SendNow);
    void DZFM(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DZFE(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void SELLR(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DZFB(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void MONO(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DCKB(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DCKS(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DP(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void LATT(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode, boolean SendNow);
    void RATT(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode, boolean SendNow);
    void SSLOW(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void INVR(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void INVL(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable, boolean SendNow);
    void DSDSEL(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode, boolean SendNow);
    void DSDD(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode, boolean SendNow);
    void DMRE(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
    void DMC(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
    void DMR(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
    void DML(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
    void DDM(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
    void SYNCE(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
    void SC(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode, boolean SendNow);
    void DSDF(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable, boolean SendNow);
private:
    static boolean Initialized[CSELECT_MAX][CHIPNUM_MAX];
    static boolean SPI_exec;
    static boolean queued[CSELECT_MAX][CHIPNUM_MAX][REGNUM];
    static uint8_t reg449x[CSELECT_MAX][CHIPNUM_MAX][REGNUM];
    void AK449x_SPI_Write(uint8_t ChipSelect, uint8_t ChipNum, uint8_t RegisterAddress);
};
    
#endif
    
