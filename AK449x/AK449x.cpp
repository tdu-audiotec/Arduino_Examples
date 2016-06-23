#include <AK449x.h>
#include <SPI.h>
#include <Wire.h>

//#include <SPI.h>
//#include <Wire.h>
//#define CSELECT_MAX 10
//#define CHIPADDR_MAX 4
//#define REGADDR 10
//#define REGNUM 8
//#define BIT_HIGH 1
//#define BIT_LOW 0
//#define BIT_RW 1
//#define BIT_RO 0
//#define VAL_WRITE BIT_HIGH
//#define VAL_READ BIT_LOW
////CHIP-SELECT
//#define VERITA9x_CHIP0 0
//#define VERITA9x_CHIP1 1
//#define VERITA9x_CHIP2 2
//#define VERITA9x_CHIP3 3
////For AK4490EQ
//#define VERITA9x_REG_CTRL1 0 //00H
//#define VERITA9x_00RSTN 0 //00H, 0
//#define VERITA9x_00RSTN_init BIT_LOW //00H, 0, LOW
//#define VERITA9x_00RSTN_perm BIT_RO
//#define VERITA9x_01DIF0 1 //00H, 1
//#define VERITA9x_01DIF0_init BIT_LOW //00H, 1, LOW
//#define VERITA9x_01DIF0_perm BIT_RO
//#define VERITA9x_02DIF1 2 //00H, 2
//#define VERITA9x_02DIF1_init BIT_HIGH //00H, 2, HIGH
//#define VERITA9x_02DIF1_perm BIT_RO
//#define VERITA9x_03DIF2 3 //00H, 3
//#define VERITA9x_03DIF2_init BIT_LOW //00H, 3, LOW
//#define VERITA9x_03DIF2_perm BIT_RO
//#define VERITA9x_04RSVD 4 //00H, 4
//#define VERITA9x_04RSVD_init BIT_LOW //00H, 4, LOW
//#define VERITA9x_04RSVD_perm BIT_RO
//#define VERITA9x_05ECS 5 //00H, 5
//#define VERITA9x_05ECS_init BIT_LOW //00H, 5, LOW
//#define VERITA9x_05ECS_perm BIT_RO
//#define VERITA9x_06EXDF 6 //00H, 6
//#define VERITA9x_06EXDF_init BIT_LOW //00H, 6, LOW
//#define VERITA9x_06EXDF_perm BIT_RO
//#define VERITA9x_07ACKS 7 //00H, 7
//#define VERITA9x_07ACKS_init BIT_LOW //00H, 7, LOW
//#define VERITA9x_07ACKS_perm BIT_RO
//#define VERITA9x_REG_CTRL2 1 //01H
//#define VERITA9x_10SMUTE 0 //01H, 0
//#define VERITA9x_10SMUTE_init BIT_LOW //01H, 0, LOW
//#define VERITA9x_10SMUTE_perm BIT_RO
//#define VERITA9x_11DEM0 1 //01H, 1
//#define VERITA9x_11DEM0_init BIT_HIGH //01H, 1, HIGH
//#define VERITA9x_11DEM0_perm BIT_RO
//#define VERITA9x_12DEM1 2 //01H, 2
//#define VERITA9x_12DEM1_init BIT_LOW //01H, 2, LOW
//#define VERITA9x_12DEM1_perm BIT_RO
//#define VERITA9x_13DFS0 3 //01H, 3
//#define VERITA9x_13DFS0_init BIT_LOW //01H, 3, LOW
//#define VERITA9x_13DFS0_perm BIT_RO
//#define VERITA9x_14DFS1 4 //01H, 4
//#define VERITA9x_14DFS1_init BIT_LOW //01H, 4, LOW
//#define VERITA9x_14DFS1_perm BIT_RO
//#define VERITA9x_15SD 5 //01H, 5
//#define VERITA9x_15SD_init BIT_HIGH //01H, 5, HIGH
//#define VERITA9x_15SD_perm BIT_RO
//#define VERITA9x_16DZFM 6 //01H, 6
//#define VERITA9x_16DZFM_init BIT_LOW //01H, 6, LOW
//#define VERITA9x_16DZFM_perm BIT_RO
//#define VERITA9x_17DZFE 7 //01H, 7
//#define VERITA9x_17DZFE_init BIT_LOW //01H, 7, LOW
//#define VERITA9x_17DZFE_perm BIT_RO
//#define VERITA9x_REG_CTRL3 2 //02H
//#define VERITA9x_20SLOW 0 //02H, 0
//#define VERITA9x_20SLOW_init BIT_LOW //02H, 0, LOW
//#define VERITA9x_20SLOW_perm BIT_RO
//#define VERITA9x_21SELLR 1 //02H, 1
//#define VERITA9x_21SELLR_init BIT_LOW //02H, 1, LOW
//#define VERITA9x_21SELLR_perm BIT_RO
//#define VERITA9x_22DZFB 2 //02H, 2
//#define VERITA9x_22DZFB_init BIT_LOW //02H, 2, LOW
//#define VERITA9x_22DZFB_perm BIT_RO
//#define VERITA9x_23MONO 3 //02H, 3
//#define VERITA9x_23MONO_init BIT_LOW //02H, 3, LOW
//#define VERITA9x_23MONO_perm BIT_RO
//#define VERITA9x_24DCKB 4 //02H, 4
//#define VERITA9x_24DCKB_init BIT_LOW //02H, 4, LOW
//#define VERITA9x_24DCKB_perm BIT_RO
//#define VERITA9x_25DCKS 5 //02H, 5
//#define VERITA9x_25DCKS_init BIT_LOW //02H, 5, LOW
//#define VERITA9x_25DCKS_perm BIT_RO
//#define VERITA9x_26RSVD 6 //02H, 6
//#define VERITA9x_26RSVD_init BIT_LOW //02H, 6, LOW
//#define VERITA9x_26RSVD_perm BIT_RO
//#define VERITA9x_27DP 7 //02H, 7
//#define VERITA9x_27DP_init BIT_LOW //02H, 7, LOW
//#define VERITA9x_27DP_perm BIT_RO
//#define VERITA9x_REG_LATT 3 //03H
//#define VERITA9x_30LATT0 0 //03H, 0
//#define VERITA9x_30LATT0_init BIT_HIGH //03H, 0, HIGH
//#define VERITA9x_30LATT0_perm BIT_RO
//#define VERITA9x_31LATT1 1 //03H, 1
//#define VERITA9x_31LATT1_init BIT_HIGH //03H, 1, HIGH
//#define VERITA9x_31LATT1_perm BIT_RO
//#define VERITA9x_32LATT2 2 //03H, 2
//#define VERITA9x_32LATT2_init BIT_HIGH //03H, 2, HIGH
//#define VERITA9x_32LATT2_perm BIT_RO
//#define VERITA9x_33LATT3 3 //03H, 3
//#define VERITA9x_33LATT3_init BIT_HIGH //03H, 3, HIGH
//#define VERITA9x_33LATT3_perm BIT_RO
//#define VERITA9x_34LATT4 4 //03H, 4
//#define VERITA9x_34LATT4_init BIT_HIGH //03H, 4, HIGH
//#define VERITA9x_34LATT4_perm BIT_RO
//#define VERITA9x_35LATT5 5 //03H, 5
//#define VERITA9x_35LATT5_init BIT_HIGH //03H, 5, HIGH
//#define VERITA9x_35LATT5_perm BIT_RO
//#define VERITA9x_36LATT6 6 //03H, 6
//#define VERITA9x_36LATT6_init BIT_HIGH //03H, 6, HIGH
//#define VERITA9x_36LATT6_perm BIT_RO
//#define VERITA9x_37LATT7 7 //03H, 7
//#define VERITA9x_37LATT7_init BIT_HIGH //03H, 7, HIGH
//#define VERITA9x_37LATT7_perm BIT_RO
//#define VERITA9x_REG_RATT 4 //04H
//#define VERITA9x_40RATT0 0 //04H, 0
//#define VERITA9x_40RATT0_init BIT_HIGH //04H, 0, HIGH
//#define VERITA9x_40RATT0_perm BIT_RO
//#define VERITA9x_41RATT1 1 //04H, 1
//#define VERITA9x_41RATT1_init BIT_HIGH //04H, 1, HIGH
//#define VERITA9x_41RATT1_perm BIT_RO
//#define VERITA9x_42RATT2 2 //04H, 2
//#define VERITA9x_42RATT2_init BIT_HIGH //04H, 2, HIGH
//#define VERITA9x_42RATT2_perm BIT_RO
//#define VERITA9x_43RATT3 3 //04H, 3
//#define VERITA9x_43RATT3_init BIT_HIGH //04H, 3, HIGH
//#define VERITA9x_43RATT3_perm BIT_RO
//#define VERITA9x_44RATT4 4 //04H, 4
//#define VERITA9x_44RATT4_init BIT_HIGH //04H, 4, HIGH
//#define VERITA9x_44RATT4_perm BIT_RO
//#define VERITA9x_45RATT5 5 //04H, 5
//#define VERITA9x_45RATT5_init BIT_HIGH //04H, 5, HIGH
//#define VERITA9x_45RATT5_perm BIT_RO
//#define VERITA9x_46RATT6 6 //04H, 6
//#define VERITA9x_46RATT6_init BIT_HIGH //04H, 6, HIGH
//#define VERITA9x_46RATT6_perm BIT_RO
//#define VERITA9x_47RATT7 7 //04H, 7
//#define VERITA9x_47RATT7_init BIT_HIGH //04H, 7, HIGH
//#define VERITA9x_47RATT7_perm BIT_RO
//#define VERITA9x_REG_CTRL4 5 //05H
//#define VERITA9x_50SSLOW 0 //05H, 0
//#define VERITA9x_50SSLOW_init BIT_LOW //05H, 0, LOW
//#define VERITA9x_50SSLOW_perm BIT_RO
//#define VERITA9x_51DFS2 1 //05H, 1
//#define VERITA9x_51DFS2_init BIT_LOW //05H, 1, LOW
//#define VERITA9x_51DFS2_perm BIT_RO
//#define VERITA9x_52RSVD 2 //05H, 2
//#define VERITA9x_52RSVD_init BIT_LOW //05H, 2, LOW
//#define VERITA9x_52RSVD_perm BIT_RO
//#define VERITA9x_53RSVD 3 //05H, 3
//#define VERITA9x_53RSVD_init BIT_LOW //05H, 3, LOW
//#define VERITA9x_53RSVD_perm BIT_RO
//#define VERITA9x_54RSVD 4 //05H, 4
//#define VERITA9x_54RSVD_init BIT_LOW //05H, 4, LOW
//#define VERITA9x_54RSVD_perm BIT_RO
//#define VERITA9x_55RSVD 5 //05H, 5
//#define VERITA9x_55RSVD_init BIT_LOW //05H, 5, LOW
//#define VERITA9x_55RSVD_perm BIT_RO
//#define VERITA9x_56INVR 6 //05H, 6
//#define VERITA9x_56INVR_init BIT_LOW //05H, 6, LOW
//#define VERITA9x_56INVR_perm BIT_RO
//#define VERITA9x_57INVL 7 //05H, 7
//#define VERITA9x_57INVL_init BIT_LOW //05H, 7, LOW
//#define VERITA9x_57INVL_perm BIT_RO
//#define VERITA90_REG_CTRL5 6 //06H
//#define VERITA90_60DSDSEL0 0 //06H, 0
//#define VERITA90_60DSDSEL0_init BIT_LOW //06H, 0, LOW
//#define VERITA90_60DSDSEL0_perm BIT_RO
//#define VERITA90_61DSDD 1 //06H, 1
//#define VERITA90_61DSDD_init BIT_LOW //06H, 1, LOW
//#define VERITA90_61DSDD_perm BIT_RO
//#define VERITA90_62RSVD 2 //06H, 2
//#define VERITA90_62RSVD_init BIT_LOW //06H, 2, LOW
//#define VERITA90_62RSVD_perm BIT_RO
//#define VERITA90_63DMRE 3 //06H, 3
//#define VERITA90_63DMRE_init BIT_LOW //06H, 3, LOW
//#define VERITA90_63DMRE_perm BIT_RO
//#define VERITA90_64DMC 4 //06H, 4
//#define VERITA90_64DMC_init BIT_LOW //06H, 4, LOW
//#define VERITA90_64DMC_perm BIT_RO
//#define VERITA90_65DMR 5 //06H, 5
//#define VERITA90_65DMR_init BIT_LOW //06H, 5, LOW
//#define VERITA90_65DMR_perm BIT_RO
//#define VERITA90_66DML 6 //06H, 6
//#define VERITA90_66DML_init BIT_LOW //06H, 6, LOW
//#define VERITA90_66DML_perm BIT_RO
//#define VERITA90_67DDM 7 //06H, 7
//#define VERITA90_67DDM_init BIT_LOW //06H, 7, LOW
//#define VERITA90_67DDM_perm BIT_RO
//#define VERITA90_REG_CTRL6 7 //07H
//#define VERITA90_70SYNCE 0 //07H, 0
//#define VERITA90_70SYNCE_init BIT_LOW //07H, 0, LOW
//#define VERITA90_70SYNCE_perm BIT_RO
//#define VERITA90_71RSVD 1 //07H, 1
//#define VERITA90_71RSVD_init BIT_LOW //07H, 1, LOW
//#define VERITA90_71RSVD_perm BIT_RO
//#define VERITA90_72RSVD 2 //07H, 2
//#define VERITA90_72RSVD_init BIT_LOW //07H, 2, LOW
//#define VERITA90_72RSVD_perm BIT_RO
//#define VERITA90_73RSVD 3 //07H, 3
//#define VERITA90_73RSVD_init BIT_LOW //07H, 3, LOW
//#define VERITA90_73RSVD_perm BIT_RO
//#define VERITA90_74RSVD 4 //07H, 4
//#define VERITA90_74RSVD_init BIT_LOW //07H, 4, LOW
//#define VERITA90_74RSVD_perm BIT_RO
//#define VERITA90_75RSVD 5 //07H, 5
//#define VERITA90_75RSVD_init BIT_LOW //07H, 5, LOW
//#define VERITA90_75RSVD_perm BIT_RO
//#define VERITA90_76RSVD 6 //07H, 6
//#define VERITA90_76RSVD_init BIT_LOW //07H, 6, LOW
//#define VERITA90_76RSVD_perm BIT_RO
//#define VERITA90_77RSVD 7 //07H, 7
//#define VERITA90_77RSVD_init BIT_LOW //07H, 7, LOW
//#define VERITA90_77RSVD_perm BIT_RO
//#define VERITA90_REG_CTRL7 8 //08H
//#define VERITA90_80SC0 0 //08H, 0
//#define VERITA90_80SC0_init BIT_LOW //08H, 0, LOW
//#define VERITA90_80SC0_perm BIT_RO
//#define VERITA90_81SC1 1 //08H, 1
//#define VERITA90_81SC1_init BIT_LOW //08H, 1, LOW
//#define VERITA90_81SC1_perm BIT_RO
//#define VERITA90_82RSVD 2 //08H, 2
//#define VERITA90_82RSVD_init BIT_LOW //08H, 2, LOW
//#define VERITA90_82RSVD_perm BIT_RO
//#define VERITA90_83RSVD 3 //08H, 3
//#define VERITA90_83RSVD_init BIT_LOW //08H, 3, LOW
//#define VERITA90_83RSVD_perm BIT_RO
//#define VERITA90_84RSVD 4 //08H, 4
//#define VERITA90_84RSVD_init BIT_LOW //08H, 4, LOW
//#define VERITA90_84RSVD_perm BIT_RO
//#define VERITA90_85RSVD 5 //08H, 5
//#define VERITA90_85RSVD_init BIT_LOW //08H, 5, LOW
//#define VERITA90_85RSVD_perm BIT_RO
//#define VERITA90_86RSVD 6 //08H, 6
//#define VERITA90_86RSVD_init BIT_LOW //08H, 6, LOW
//#define VERITA90_86RSVD_perm BIT_RO
//#define VERITA90_87RSVD 7 //08H, 7
//#define VERITA90_87RSVD_init BIT_LOW //08H, 7, LOW
//#define VERITA90_87RSVD_perm BIT_RO
//#define VERITA90_REG_CTRL8 9 //09H
//#define VERITA90_90DSDSEL1 0 //09H, 0
//#define VERITA90_90DSDSEL1_init BIT_LOW //09H, 0, LOW
//#define VERITA90_90DSDSEL1_perm BIT_RO
//#define VERITA90_91DSDF 1 //09H, 1
//#define VERITA90_91DSDF_init BIT_LOW //09H, 1, LOW
//#define VERITA90_91DSDF_perm BIT_RO
//#define VERITA90_92RSVD 2 //09H, 2
//#define VERITA90_92RSVD_init BIT_LOW //09H, 2, LOW
//#define VERITA90_92RSVD_perm BIT_RO
//#define VERITA90_93RSVD 3 //09H, 3
//#define VERITA90_93RSVD_init BIT_LOW //09H, 3, LOW
//#define VERITA90_93RSVD_perm BIT_RO
//#define VERITA90_94RSVD 4 //09H, 4
//#define VERITA90_94RSVD_init BIT_LOW //09H, 4, LOW
//#define VERITA90_94RSVD_perm BIT_RO
//#define VERITA90_95RSVD 5 //09H, 5
//#define VERITA90_95RSVD_init BIT_LOW //09H, 5, LOW
//#define VERITA90_95RSVD_perm BIT_RO
//#define VERITA90_96RSVD 6 //09H, 6
//#define VERITA90_96RSVD_init BIT_LOW //09H, 6, LOW
//#define VERITA90_96RSVD_perm BIT_RO
//#define VERITA90_97RSVD 7 //09H, 7
//#define VERITA90_97RSVD_init BIT_LOW //09H, 7, LOW
//#define VERITA90_97RSVD_perm BIT_RO
//#define VERITA95_REG_CTRL5 6 //06H
//#define VERITA95_60DSDDSEL 0 //06H, 0
//#define VERITA95_60DSDDSEL_init BIT_LOW //06H, 0, LOW
//#define VERITA95_60DSDDSEL_perm BIT_RO
//#define VERITA95_61DSDD0 1 //06H, 1
//#define VERITA95_61DSDD0_init BIT_LOW //06H, 1, LOW
//#define VERITA95_61DSDD0_perm BIT_RO
//#define VERITA95_62DSDD1 2 //06H, 2
//#define VERITA95_62DSDD1_init BIT_LOW //06H, 2, LOW
//#define VERITA95_62DSDD1_perm BIT_RO
//#define VERITA95_63DMRE 3 //06H, 3
//#define VERITA95_63DMRE_init BIT_LOW //06H, 3, LOW
//#define VERITA95_63DMRE_perm BIT_RO
//#define VERITA95_64DMC 4 //06H, 4
//#define VERITA95_64DMC_init BIT_LOW //06H, 4, LOW
//#define VERITA95_64DMC_perm BIT_RO
//#define VERITA95_65DMR 5 //06H, 5
//#define VERITA95_65DMR_init BIT_LOW //06H, 5, LOW
//#define VERITA95_65DMR_perm BIT_RO
//#define VERITA95_66DML 6 //06H, 6
//#define VERITA95_66DML_init BIT_LOW //06H, 6, LOW
//#define VERITA95_66DML_perm BIT_RO
//#define VERITA95_67DDM 7 //06H, 7
//#define VERITA95_67DDM_init BIT_LOW //06H, 7, LOW
//#define VERITA95_67DDM_perm BIT_RO
//#define VERITA95_REG_CTRL6 7 //07H
//#define VERITA95_70SYNCE 0 //07H, 0
//#define VERITA95_70SYNCE_init BIT_LOW //07H, 0, LOW
//#define VERITA95_70SYNCE_perm BIT_RO
//#define VERITA95_71RSVD 1 //07H, 1
//#define VERITA95_71RSVD_init BIT_LOW //07H, 1, LOW
//#define VERITA95_71RSVD_perm BIT_RO
//#define VERITA95_72RSVD 2 //07H, 2
//#define VERITA95_72RSVD_init BIT_LOW //07H, 2, LOW
//#define VERITA95_72RSVD_perm BIT_RO
//#define VERITA95_73RSVD 3 //07H, 3
//#define VERITA95_73RSVD_init BIT_LOW //07H, 3, LOW
//#define VERITA95_73RSVD_perm BIT_RO
//#define VERITA95_74RSVD 4 //07H, 4
//#define VERITA95_74RSVD_init BIT_LOW //07H, 4, LOW
//#define VERITA95_74RSVD_perm BIT_RO
//#define VERITA95_75RSVD 5 //07H, 5
//#define VERITA95_75RSVD_init BIT_LOW //07H, 5, LOW
//#define VERITA95_75RSVD_perm BIT_RO
//#define VERITA95_76RSVD 6 //07H, 6
//#define VERITA95_76RSVD_init BIT_LOW //07H, 6, LOW
//#define VERITA95_76RSVD_perm BIT_RO
//#define VERITA95_77RSVD 7 //07H, 7
//#define VERITA95_77RSVD_init BIT_LOW //07H, 7, LOW
//#define VERITA95_77RSVD_perm BIT_RO
//#define VERITA95_REG_CTRL7 8 //08H
//#define VERITA95_80SC0 0 //08H, 0
//#define VERITA95_80SC0_init BIT_LOW //08H, 0, LOW
//#define VERITA95_80SC0_perm BIT_RO
//#define VERITA95_81SC1 1 //08H, 1
//#define VERITA95_81SC1_init BIT_LOW //08H, 1, LOW
//#define VERITA95_81SC1_perm BIT_RO
//#define VERITA95_82SC2 2 //08H, 2
//#define VERITA95_82SC2_init BIT_LOW //08H, 2, LOW
//#define VERITA95_82SC2_perm BIT_RO
//#define VERITA95_83RSVD 3 //08H, 3
//#define VERITA95_83RSVD_init BIT_LOW //08H, 3, LOW
//#define VERITA95_83RSVD_perm BIT_RO
//#define VERITA95_84RSVD 4 //08H, 4
//#define VERITA95_84RSVD_init BIT_LOW //08H, 4, LOW
//#define VERITA95_84RSVD_perm BIT_RO
//#define VERITA95_85RSVD 5 //08H, 5
//#define VERITA95_85RSVD_init BIT_LOW //08H, 5, LOW
//#define VERITA95_85RSVD_perm BIT_RO
//#define VERITA95_86RSVD 6 //08H, 6
//#define VERITA95_86RSVD_init BIT_LOW //08H, 6, LOW
//#define VERITA95_86RSVD_perm BIT_RO
//#define VERITA95_87RSVD 7 //08H, 7
//#define VERITA95_87RSVD_init BIT_LOW //08H, 7, LOW
//#define VERITA95_87RSVD_perm BIT_RO
//#define VERITA95_REG_RSVD 9 //09H
//#define VERITA95_90DSDSEL1 0 //09H, 0
//#define VERITA95_90DSDSEL1_init BIT_LOW //09H, 0, LOW
//#define VERITA95_90DSDSEL1_perm BIT_RO
//#define VERITA95_91DSDF 1 //09H, 1
//#define VERITA95_91DSDF_init BIT_LOW //09H, 1, LOW
//#define VERITA95_91DSDF_perm BIT_RO
//#define VERITA95_92RSVD 2 //09H, 2
//#define VERITA95_92RSVD_init BIT_LOW //09H, 2, LOW
//#define VERITA95_92RSVD_perm BIT_RO
//#define VERITA95_93RSVD 3 //09H, 3
//#define VERITA95_93RSVD_init BIT_LOW //09H, 3, LOW
//#define VERITA95_93RSVD_perm BIT_RO
//#define VERITA95_94RSVD 4 //09H, 4
//#define VERITA95_94RSVD_init BIT_LOW //09H, 4, LOW
//#define VERITA95_94RSVD_perm BIT_RO
//#define VERITA95_95RSVD 5 //09H, 5
//#define VERITA95_95RSVD_init BIT_LOW //09H, 5, LOW
//#define VERITA95_95RSVD_perm BIT_RO
//#define VERITA95_96RSVD 6 //09H, 6
//#define VERITA95_96RSVD_init BIT_LOW //09H, 6, LOW
//#define VERITA95_96RSVD_perm BIT_RO
//#define VERITA95_97RSVD 7 //09H, 7
//#define VERITA95_97RSVD_init BIT_LOW //09H, 7, LOW
//#define VERITA95_97RSVD_perm BIT_RO

//class AK449x{
//public:
void AK449x::setinit(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean spi) {
    if (!status_init[ChipSelect][ChipAddr]) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_00RSTN, VERITA9x_00RSTN_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_01DIF0, VERITA9x_01DIF0_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_02DIF1, VERITA9x_02DIF1_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_03DIF2, VERITA9x_03DIF2_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_04RSVD, VERITA9x_04RSVD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_05ECS, VERITA9x_05ECS_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_06EXDF, VERITA9x_06EXDF_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_07ACKS, VERITA9x_07ACKS_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_10SMUTE, VERITA9x_10SMUTE_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_11DEM0, VERITA9x_11DEM0_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_12DEM1, VERITA9x_12DEM1_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_13DFS0, VERITA9x_13DFS0_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_14DFS1, VERITA9x_14DFS1_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_15SD, VERITA9x_15SD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_16DZFM, VERITA9x_16DZFM_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_17DZFE, VERITA9x_17DZFE_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_21SELLR, VERITA9x_21SELLR_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_22DZFB, VERITA9x_22DZFB_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_23MONO, VERITA9x_23MONO_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_24DCKB, VERITA9x_24DCKB_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_25DCKS, VERITA9x_25DCKS_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_26RSVD, VERITA9x_26RSVD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_27DP, VERITA9x_27DP_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_50SSLOW, VERITA9x_50SSLOW_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_51DFS2, VERITA9x_51DFS2_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_52RSVD, VERITA9x_52RSVD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_53RSVD, VERITA9x_53RSVD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_54RSVD, VERITA9x_54RSVD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_55RSVD, VERITA9x_55RSVD_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_56INVR, VERITA9x_56INVR_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_57INVL, VERITA9x_57INVL_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_30LATT0, VERITA9x_30LATT0_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_31LATT1, VERITA9x_31LATT1_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_32LATT2, VERITA9x_32LATT2_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_33LATT3, VERITA9x_33LATT3_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_34LATT4, VERITA9x_34LATT4_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_35LATT5, VERITA9x_35LATT5_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_36LATT6, VERITA9x_36LATT6_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_37LATT7, VERITA9x_37LATT7_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_40RATT0, VERITA9x_40RATT0_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_41RATT1, VERITA9x_41RATT1_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_42RATT2, VERITA9x_42RATT2_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_43RATT3, VERITA9x_43RATT3_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_44RATT4, VERITA9x_44RATT4_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_45RATT5, VERITA9x_45RATT5_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_46RATT6, VERITA9x_46RATT6_init);
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_47RATT7, VERITA9x_47RATT7_init);
        if (ModelNum == 4490) {
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_60DSDSEL0, VERITA90_60DSDSEL0_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_61DSDD, VERITA90_61DSDD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_62RSVD, VERITA90_62RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_63DMRE, VERITA90_63DMRE_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_64DMC, VERITA90_64DMC_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_65DMR, VERITA90_65DMR_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_66DML, VERITA90_66DML_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_67DDM, VERITA90_67DDM_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_70SYNCE, VERITA90_70SYNCE_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_71RSVD, VERITA90_71RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_72RSVD, VERITA90_72RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_73RSVD, VERITA90_73RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_74RSVD, VERITA90_74RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_75RSVD, VERITA90_75RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_76RSVD, VERITA90_76RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_77RSVD, VERITA90_77RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_80SC0, VERITA90_80SC0_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_81SC1, VERITA90_81SC1_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_82RSVD, VERITA90_82RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_83RSVD, VERITA90_83RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_84RSVD, VERITA90_84RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_85RSVD, VERITA90_85RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_86RSVD, VERITA90_86RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_87RSVD, VERITA90_87RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_90DSDSEL1, VERITA90_90DSDSEL1_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_91DSDF, VERITA90_91DSDF_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_92RSVD, VERITA90_92RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_93RSVD, VERITA90_93RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_94RSVD, VERITA90_94RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_95RSVD, VERITA90_95RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_96RSVD, VERITA90_96RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_97RSVD, VERITA90_97RSVD_init);
            status_init[ChipSelect][ChipAddr] = true;
        } else if (ModelNum == 4495) {
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_60DSDDSEL, VERITA95_60DSDDSEL_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_61DSDD0, VERITA95_61DSDD0_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_62DSDD1, VERITA95_62DSDD1_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_63DMRE, VERITA95_63DMRE_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_64DMC, VERITA95_64DMC_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_65DMR, VERITA95_65DMR_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_66DML, VERITA95_66DML_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_67DDM, VERITA95_67DDM_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_70SYNCE, VERITA95_70SYNCE_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_71RSVD, VERITA95_71RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_72RSVD, VERITA95_72RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_73RSVD, VERITA95_73RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_74RSVD, VERITA95_74RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_75RSVD, VERITA95_75RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_76RSVD, VERITA95_76RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL6], VERITA95_77RSVD, VERITA95_77RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_80SC0, VERITA95_80SC0_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_81SC1, VERITA95_81SC1_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_82SC2, VERITA95_82SC2_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_83RSVD, VERITA95_83RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_84RSVD, VERITA95_84RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_85RSVD, VERITA95_85RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_86RSVD, VERITA95_86RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_87RSVD, VERITA95_87RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_90DSDSEL1, VERITA95_90DSDSEL1_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_91DSDF, VERITA95_91DSDF_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_92RSVD, VERITA95_92RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_93RSVD, VERITA95_93RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_94RSVD, VERITA95_94RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_95RSVD, VERITA95_95RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_96RSVD, VERITA95_96RSVD_init);
            bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_RSVD], VERITA95_97RSVD, VERITA95_97RSVD_init);
            status_init[ChipSelect][ChipAddr] = true;
        }
    }
    if (spi && (!comm_init)) {
        SPI.begin();
        SPI.setDataMode(SPI_MODE0);
        AK449x::use_spi = spi;
        comm_init = true;
    } else if (!spi && (!comm_init)) {
        Wire.begin();
        AK449x::i2c_permission(ModelNum);
        AK449x::use_spi = spi;
        comm_init = true;
    }
    AK449x::bulk_write(ChipSelect, ChipAddr);
}

////Register address: 00 (Control 1)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Reset chip without initializing registers
////|_|_|_|_|x|x|x|_| Interface mode: 16bit, 24bit, 32bit, I2S, LJ... (1)
////|_|_|x|_|_|_|_|_| External digital filter clock: 768KHz/384KHz
////|_|x|_|_|_|_|_|_| Enable/disable external digital filter mode
////|x|_|_|_|_|_|_|_| Master Clock frequency Setting: auto/manual (2)(3)
void AK449x::retn(uint8_t ChipSelect, uint8_t ChipAddr) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_00RSTN, BIT_HIGH);
    AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL1);
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_00RSTN, BIT_LOW);
    AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL1);
}

void AK449x::dif(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t OpMode, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_01DIF0, bitRead(OpMode, 0));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_02DIF1, bitRead(OpMode, 1));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_03DIF2, bitRead(OpMode, 2));
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL1);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = true;
    }
}

void AK449x::ecs(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_05ECS, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL1);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = true;
    }
}

void AK449x::exdf(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_06EXDF, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL1);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = true;
    }
}

void AK449x::acks(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1], VERITA9x_07ACKS, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL1);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL1] = true;
    }
}

////Register address: 01 (Control 2)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Mute
////|_|_|_|_|_|x|x|_| De-emphasis: Off, 32KHz, 44.1KHz, 48KHz
////|_|_|_|x|x|_|_|_| Manual setting of sampling speed: "normal", "double"... (1)
////|_|_|x|_|_|_|_|_| Short Delay/Traditional filter (Minimum/Linear phase)
////|_|x|_|_|_|_|_|_| Zero data detect mode: Separate channels or ANDed channels
////|x|_|_|_|_|_|_|_| Zero data detect ON/OFF
void AK449x::smute(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_10SMUTE, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL2);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = true;
    }
}

void AK449x::dem(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t OpMode, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_11DEM0, bitRead(OpMode, 0));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_12DEM1, bitRead(OpMode, 1));
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL2);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = true;
    }
}

void AK449x::dfs(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t OpMode, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_13DFS0, bitRead(OpMode, 0));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_14DFS1, bitRead(OpMode, 1));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_51DFS2, bitRead(OpMode, 2));
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL2);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = true;
    }
}

void AK449x::sd(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t OpMode, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_15SD, bitRead(OpMode, 1));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_50SSLOW, bitRead(OpMode, 0));
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL2);
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = false;
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = true;
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

void AK449x::dzfm(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_16DZFM, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL2);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = true;
    }
}

void AK449x::dzfe(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2], VERITA9x_17DZFE, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL2);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL2] = true;
    }
}

////Register address: 02 (Control 3)
////7 6 5 4 3 2 1 0n
////|_|_|_|_|_|_|_|x| Filter cutoff slope: fast/slow
////|_|_|_|_|_|_|x|_| 23MONO mode: left/right
////|_|_|_|_|_|x|_|_| Invert output pin level on zero detect
////|_|_|_|_|x|_|_|_| 23MONO/STEREO mode
////|_|_|_|x|_|_|_|_| DSD Data on clock falling/rising edge
////|_|x|_|_|_|_|_|_| DSD master clock frequency:512KHz/768KHz
////|x|_|_|_|_|_|_|_| PCM/DSD mode
void AK449x::sellr(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_21SELLR, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

void AK449x::dzfb(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_22DZFB, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

void AK449x::mono(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_23MONO, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

void AK449x::dckb(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_24DCKB, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

void AK449x::dcks(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_25DCKS, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

void AK449x::DP(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3], VERITA9x_27DP, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL3);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL3] = true;
    }
}

////Register address: 03 (Left Channel Attenuation)
////7 6 5 4 3 2 1 0
////|x|x|x|x|x|x|x|x| Attenuation (1)
void AK449x::latt(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t OpMode, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_30LATT0, bitRead(OpMode, 0));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_31LATT1, bitRead(OpMode, 1));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_32LATT2, bitRead(OpMode, 2));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_33LATT3, bitRead(OpMode, 3));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_34LATT4, bitRead(OpMode, 4));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_35LATT5, bitRead(OpMode, 5));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_36LATT6, bitRead(OpMode, 6));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_LATT], VERITA9x_37LATT7, bitRead(OpMode, 7));
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_LATT);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_LATT] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_LATT] = true;
    }
}

////Register address: 04 (Right Channel Attenuation)
////7 6 5 4 3 2 1 0
////|x|x|x|x|x|x|x|x| Attenuation (1)
void AK449x::ratt(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t OpMode, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_40RATT0, bitRead(OpMode, 0));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_41RATT1, bitRead(OpMode, 1));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_42RATT2, bitRead(OpMode, 2));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_43RATT3, bitRead(OpMode, 3));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_44RATT4, bitRead(OpMode, 4));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_45RATT5, bitRead(OpMode, 5));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_46RATT6, bitRead(OpMode, 6));
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_RATT], VERITA9x_47RATT7, bitRead(OpMode, 7));
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_RATT);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_RATT] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_RATT] = true;
    }
}

////Register address: 05 (Control 4)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Super Slow filter on/off
////|_|_|_|_|_|_|x|_| Bit 3 of the manual sampling speed setting (see reg 01)
////|_|x|_|_|_|_|_|_| Left channel phase invert ON/OFF
////|x|_|_|_|_|_|_|_| Right channel phase invert ON/OFF
void AK449x::sslow(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_50SSLOW, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL4);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4] = true;
    }
}

void AK449x::invr(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_56INVR, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL4);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4] = true;
    }
}

void AK449x::invl(uint8_t ChipSelect, uint8_t ChipAddr, boolean FuncEnable, boolean SendNow) {
    bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4], VERITA9x_57INVL, FuncEnable);
    if (SendNow) {
        AK449x::single_write(ChipSelect, ChipAddr, VERITA9x_REG_CTRL4);
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4] = false;
    } else if (!SendNow) {
        AK449x::status_queued[ChipSelect][ChipAddr][VERITA9x_REG_CTRL4] = true;
    }
}

////Register address: 06 (control 5)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| DSD bit 0 of sampling speed selection (bit 1 is in reg 9)(1)
////|_|_|_|_|_|_|x|_| DSD Mode: Direct/Convert to PCM (2)
////|_|_|_|_|x|_|_|_| DSD Auto-mute release when Auto-mute release is in "hold"
////|_|_|_|x|_|_|_|_| Auto-mute release: Auto/hold (3)
////|_|_|x|_|_|_|_|_| Right Channel DSD flag when detecting full scale signal
////|_|x|_|_|_|_|_|_| Left Channel DSD flag when detecting full scale signal
////|x|_|_|_|_|_|_|_| DSD AutoMute: ON/OFF (4)
void AK449x::dsdsel(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, uint8_t OpMode, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_60DSDSEL0, bitRead(OpMode, 0));
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_90DSDSEL1, bitRead(OpMode, 1));
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL8);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL8] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL8] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_60DSDDSEL, bitRead(OpMode, 0));
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

void AK449x::dsdd(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, uint8_t OpMode, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_61DSDD, bitRead(OpMode, 0));
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_61DSDD0, bitRead(OpMode, 0));
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_62DSDD1, bitRead(OpMode, 1));
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

void AK449x::dmre(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_63DMRE, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_63DMRE, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

void AK449x::dmc(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_64DMC, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_64DMC, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

void AK449x::dmr(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_65DMR, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_65DMR, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

void AK449x::dml(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_66DML, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_66DML, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

void AK449x::ddm(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL5], VERITA90_67DDM, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL5] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL5], VERITA95_67DDM, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL5);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL5] = true;
        }
    }
}

////Register address: 07 (Control 6)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Synchronize ON/OFF (1)
void AK449x::synce(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA90_70SYNCE, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL6);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL6] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL6] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL6], VERITA95_70SYNCE, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL6);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL6] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL6] = true;
        }
    }
}

////Register address: 08 (Control 7)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|x|x| Sound Quality Control Setting (1)
void AK449x::sc(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, uint8_t OpMode, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_80SC0, bitRead(OpMode, 0));
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL7], VERITA90_81SC1, bitRead(OpMode, 1));
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL7);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL7] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL7] = true;
        }
    } else if (ModelNum == 4495) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_80SC0, bitRead(OpMode, 0));
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_81SC1, bitRead(OpMode, 1));
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA95_REG_CTRL7], VERITA95_82SC2, bitRead(OpMode, 2));
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA95_REG_CTRL7);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL7] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA95_REG_CTRL7] = true;
        }
    }
}

////Register address: 09 (Control 8)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| DSD bit 1 of sample speed selection (see also reg 5)
////|_|_|_|_|_|_|x|_| DSD filter selection when in DSD direct mode
void AK449x::dsdf(uint8_t ChipSelect, uint8_t ChipAddr, int ModelNum, boolean FuncEnable, boolean SendNow) {
    if (ModelNum == 4490) {
        bitWrite(reg_byte[ChipSelect][ChipAddr][VERITA90_REG_CTRL8], VERITA90_91DSDF, FuncEnable);
        if (SendNow) {
            AK449x::single_write(ChipSelect, ChipAddr, VERITA90_REG_CTRL8);
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL8] = false;
        } else if (!SendNow) {
            AK449x::status_queued[ChipSelect][ChipAddr][VERITA90_REG_CTRL8] = true;
        }
    }
}

void AK449x::bulk_write(uint8_t ChipSelect, uint8_t ChipAddr) {
    if (AK449x::use_spi && AK449x::comm_init) {
        for (uint8_t i = 0; i < REGNUM; i++) {
            AK449x::write_byte_spi(ChipSelect, ChipAddr, i);
        }
    } else if (!AK449x::use_spi && AK449x::comm_init) {
        Wire.beginTransmission(ChipAddr);
        for (uint8_t i = 0; i < REGNUM; i++) {
            AK449x::write_byte_i2c(ChipSelect, ChipAddr, i);
        }
        Wire.endTransmission();
    }
}

//private:
//static boolean AK449x::comm_init;
//static boolean AK449x::status_init[CSELECT_MAX][CHIPADDR_MAX];
//static boolean AK449x::use_spi;
//static boolean AK449x::status_queued[CSELECT_MAX][CHIPADDR_MAX][REGNUM];
//static uint8_t AK449x::i2s_perm[REGNUM];
//static uint8_t AK449x::reg_byte[CSELECT_MAX][CHIPADDR_MAX][REGNUM];
    boolean AK449x::comm_init;
    boolean AK449x::status_init[CSELECT_MAX][CHIPADDR_MAX];
    boolean AK449x::use_spi;
    boolean AK449x::status_queued[CSELECT_MAX][CHIPADDR_MAX][REGNUM];
    uint8_t AK449x::i2s_perm[REGNUM];
    uint8_t AK449x::reg_byte[CSELECT_MAX][CHIPADDR_MAX][REGNUM];

void AK449x::i2c_permission(int ModelNum) {
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_00RSTN, VERITA9x_00RSTN_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_01DIF0, VERITA9x_01DIF0_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_02DIF1, VERITA9x_02DIF1_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_03DIF2, VERITA9x_03DIF2_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_04RSVD, VERITA9x_04RSVD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_05ECS, VERITA9x_05ECS_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_06EXDF, VERITA9x_06EXDF_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL1], VERITA9x_07ACKS, VERITA9x_07ACKS_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_10SMUTE, VERITA9x_10SMUTE_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_11DEM0, VERITA9x_11DEM0_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_12DEM1, VERITA9x_12DEM1_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_13DFS0, VERITA9x_13DFS0_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_14DFS1, VERITA9x_14DFS1_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_15SD, VERITA9x_15SD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_16DZFM, VERITA9x_16DZFM_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL2], VERITA9x_17DZFE, VERITA9x_17DZFE_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_21SELLR, VERITA9x_21SELLR_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_22DZFB, VERITA9x_22DZFB_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_23MONO, VERITA9x_23MONO_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_24DCKB, VERITA9x_24DCKB_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_25DCKS, VERITA9x_25DCKS_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_26RSVD, VERITA9x_26RSVD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_27DP, VERITA9x_27DP_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL3], VERITA9x_50SSLOW, VERITA9x_50SSLOW_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_51DFS2, VERITA9x_51DFS2_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_52RSVD, VERITA9x_52RSVD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_53RSVD, VERITA9x_53RSVD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_54RSVD, VERITA9x_54RSVD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_55RSVD, VERITA9x_55RSVD_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_56INVR, VERITA9x_56INVR_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_CTRL4], VERITA9x_57INVL, VERITA9x_57INVL_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_30LATT0, VERITA9x_30LATT0_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_31LATT1, VERITA9x_31LATT1_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_32LATT2, VERITA9x_32LATT2_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_33LATT3, VERITA9x_33LATT3_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_34LATT4, VERITA9x_34LATT4_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_35LATT5, VERITA9x_35LATT5_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_36LATT6, VERITA9x_36LATT6_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_LATT], VERITA9x_37LATT7, VERITA9x_37LATT7_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_40RATT0, VERITA9x_40RATT0_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_41RATT1, VERITA9x_41RATT1_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_42RATT2, VERITA9x_42RATT2_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_43RATT3, VERITA9x_43RATT3_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_44RATT4, VERITA9x_44RATT4_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_45RATT5, VERITA9x_45RATT5_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_46RATT6, VERITA9x_46RATT6_perm);
    bitWrite(AK449x::i2s_perm[VERITA9x_REG_RATT], VERITA9x_47RATT7, VERITA9x_47RATT7_perm);
    if (ModelNum == 4490) {
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_60DSDSEL0, VERITA90_60DSDSEL0_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_61DSDD, VERITA90_61DSDD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_62RSVD, VERITA90_62RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_63DMRE, VERITA90_63DMRE_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_64DMC, VERITA90_64DMC_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_65DMR, VERITA90_65DMR_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_66DML, VERITA90_66DML_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL5], VERITA90_67DDM, VERITA90_67DDM_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_70SYNCE, VERITA90_70SYNCE_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_71RSVD, VERITA90_71RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_72RSVD, VERITA90_72RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_73RSVD, VERITA90_73RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_74RSVD, VERITA90_74RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_75RSVD, VERITA90_75RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_76RSVD, VERITA90_76RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL6], VERITA90_77RSVD, VERITA90_77RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_80SC0, VERITA90_80SC0_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_81SC1, VERITA90_81SC1_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_82RSVD, VERITA90_82RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_83RSVD, VERITA90_83RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_84RSVD, VERITA90_84RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_85RSVD, VERITA90_85RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_86RSVD, VERITA90_86RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL7], VERITA90_87RSVD, VERITA90_87RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_90DSDSEL1, VERITA90_90DSDSEL1_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_91DSDF, VERITA90_91DSDF_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_92RSVD, VERITA90_92RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_93RSVD, VERITA90_93RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_94RSVD, VERITA90_94RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_95RSVD, VERITA90_95RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_96RSVD, VERITA90_96RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA90_REG_CTRL8], VERITA90_97RSVD, VERITA90_97RSVD_perm);
    } else if (ModelNum == 4495) {
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_60DSDDSEL, VERITA95_60DSDDSEL_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_61DSDD0, VERITA95_61DSDD0_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_62DSDD1, VERITA95_62DSDD1_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_63DMRE, VERITA95_63DMRE_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_64DMC, VERITA95_64DMC_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_65DMR, VERITA95_65DMR_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_66DML, VERITA95_66DML_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL5], VERITA95_67DDM, VERITA95_67DDM_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_70SYNCE, VERITA95_70SYNCE_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_71RSVD, VERITA95_71RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_72RSVD, VERITA95_72RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_73RSVD, VERITA95_73RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_74RSVD, VERITA95_74RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_75RSVD, VERITA95_75RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_76RSVD, VERITA95_76RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL6], VERITA95_77RSVD, VERITA95_77RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_80SC0, VERITA95_80SC0_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_81SC1, VERITA95_81SC1_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_82SC2, VERITA95_82SC2_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_83RSVD, VERITA95_83RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_84RSVD, VERITA95_84RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_85RSVD, VERITA95_85RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_86RSVD, VERITA95_86RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_CTRL7], VERITA95_87RSVD, VERITA95_87RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_90DSDSEL1, VERITA95_90DSDSEL1_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_91DSDF, VERITA95_91DSDF_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_92RSVD, VERITA95_92RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_93RSVD, VERITA95_93RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_94RSVD, VERITA95_94RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_95RSVD, VERITA95_95RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_96RSVD, VERITA95_96RSVD_perm);
        bitWrite(AK449x::i2s_perm[VERITA95_REG_RSVD], VERITA95_97RSVD, VERITA95_97RSVD_perm);
    }
}

void AK449x::single_write(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t RegAddr) {
    if (AK449x::use_spi && AK449x::comm_init) {
        AK449x::write_byte_spi(ChipSelect, ChipAddr, RegAddr);
    } else if (!AK449x::use_spi && AK449x::comm_init) {
        Wire.beginTransmission(ChipAddr);
        AK449x::write_byte_i2c(ChipSelect, ChipAddr, RegAddr);
        Wire.endTransmission();
    }
}

void AK449x::write_byte_spi(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t RegAddr) {
    byte ChipAddrByte = (byte) ChipAddr << 6;
    byte ReadWriteByte = (byte) 1 << 7;
    byte RegAddrByte = (byte) RegAddr << 3;
    byte CtrlDataByte = (byte) reg_byte[ChipSelect][ChipAddr][RegAddr];
    word WordToSend = ChipAddrByte | ReadWriteByte | RegAddrByte | CtrlDataByte;
    digitalWrite(ChipSelect, LOW);
    SPI.transfer16(WordToSend);
    digitalWrite(ChipSelect, HIGH);
}

void AK449x::write_byte_i2c(uint8_t ChipSelect, uint8_t ChipAddr, uint8_t RegAddr) {
    byte SlaveAddrByte = (byte) 2 << 3 | (byte) ChipAddr << 6 | (byte) 0 << 7;
    byte SubAddrByte = (byte) 0 << 5 | (byte) RegAddr << 3;
    byte CtrlDataByte = (byte) reg_byte[ChipSelect][ChipAddr][RegAddr];
    Wire.write(SlaveAddrByte);
    Wire.write(SubAddrByte);
    Wire.write(CtrlDataByte);
}
//};