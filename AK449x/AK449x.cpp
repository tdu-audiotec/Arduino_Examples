////include the SPI library:
#include <AK449x.h>

//#include <SPI.h>
//#include <Wire.h>
//#define CSELECT_MAX 10
//#define CHIPNUM_MAX 4
//#define REGADDR 10
//#define REGNUM 8
//#define BIT_HIGH 1
//#define BIT_LOW 0
//#define VAL_WRITE BIT_HIGH
//#define VAL_READ BIT_LOW
////For AK4490EQ
////CHIP-SELECT
//#define AK4490EQ_CHIP0 0
//#define AK4490EQ_CHIP1 1
//#define AK4490EQ_CHIP2 2
//#define AK4490EQ_CHIP3 3
////00H
//#define AK4490EQ_REG_CTRL_1 0
//#define AK4490EQ_ACKS 7
//#define AK4490EQ_ACKS_default BIT_LOW
//#define AK4490EQ_EXDF 6
//#define AK4490EQ_EXDF_default BIT_LOW
//#define AK4490EQ_ECS 5
//#define AK4490EQ_ECS_default BIT_LOW
//#define AK4490EQ_UNUSED_04 4
//#define AK4490EQ_UNUSED_04_default BIT_LOW
//#define AK4490EQ_DIF_2 3
//#define AK4490EQ_DIF_2_default BIT_LOW
//#define AK4490EQ_DIF_1 2
//#define AK4490EQ_DIF_1_default BIT_HIGH
//#define AK4490EQ_DIF_0 1
//#define AK4490EQ_DIF_0_default BIT_LOW
//#define AK4490EQ_RSTN 0
//#define AK4490EQ_RSTN_default BIT_LOW
////01H
//#define AK4490EQ_REG_CTRL_2 1
//#define AK4490EQ_DZFE 7
//#define AK4490EQ_DZFE_default BIT_LOW
//#define AK4490EQ_DZFM 6
//#define AK4490EQ_DZFM_default BIT_LOW
//#define AK4490EQ_SD 5
//#define AK4490EQ_SD_default BIT_HIGH
//#define AK4490EQ_DFS_1 4
//#define AK4490EQ_DFS_1_default BIT_LOW
//#define AK4490EQ_DFS_0 3
//#define AK4490EQ_DFS_0_default BIT_LOW
//#define AK4490EQ_DEM_1 2
//#define AK4490EQ_DEM_1_default BIT_LOW
//#define AK4490EQ_DEM_0 1
//#define AK4490EQ_DEM_0_default BIT_HIGH
//#define AK4490EQ_SMUTE 0
//#define AK4490EQ_SMUTE_default BIT_LOW
////02H
//#define AK4490EQ_REG_CTRL_3 2
//#define AK4490EQ_DP 7
//#define AK4490EQ_DP_default BIT_LOW
//#define AK4490EQ_UNUSED_26 6
//#define AK4490EQ_UNUSED_26_default BIT_LOW
//#define AK4490EQ_DCKS 5
//#define AK4490EQ_DCKS_default BIT_LOW
//#define AK4490EQ_DCKB 4
//#define AK4490EQ_DCKB_default BIT_LOW
//#define AK4490EQ_MONO 3
//#define AK4490EQ_MONO_default BIT_LOW
//#define AK4490EQ_DZFB 2
//#define AK4490EQ_DZFB_default BIT_LOW
//#define AK4490EQ_SELLR 1
//#define AK4490EQ_SELLR_default BIT_LOW
//#define AK4490EQ_SSLOW 0
//#define AK4490EQ_SSLOW_default BIT_LOW
////03H
//#define AK4490EQ_REG_ATT_L 3
//#define AK4490EQ_ATT_L_7 7
//#define AK4490EQ_ATT_L_7_default BIT_HIGH
//#define AK4490EQ_ATT_L_6 6
//#define AK4490EQ_ATT_L_6_default BIT_HIGH
//#define AK4490EQ_ATT_L_5 5
//#define AK4490EQ_ATT_L_5_default BIT_HIGH
//#define AK4490EQ_ATT_L_4 4
//#define AK4490EQ_ATT_L_4_default BIT_HIGH
//#define AK4490EQ_ATT_L_3 3
//#define AK4490EQ_ATT_L_3_default BIT_HIGH
//#define AK4490EQ_ATT_L_2 2
//#define AK4490EQ_ATT_L_2_default BIT_HIGH
//#define AK4490EQ_ATT_L_1 1
//#define AK4490EQ_ATT_L_1_default BIT_HIGH
//#define AK4490EQ_ATT_L_0 0
//#define AK4490EQ_ATT_L_0_default BIT_HIGH
////04H
//#define AK4490EQ_REG_ATT_R 4
//#define AK4490EQ_ATT_R_7 7
//#define AK4490EQ_ATT_R_7_default BIT_HIGH
//#define AK4490EQ_ATT_R_6 6
//#define AK4490EQ_ATT_R_6_default BIT_HIGH
//#define AK4490EQ_ATT_R_5 5
//#define AK4490EQ_ATT_R_5_default BIT_HIGH
//#define AK4490EQ_ATT_R_4 4
//#define AK4490EQ_ATT_R_4_default BIT_HIGH
//#define AK4490EQ_ATT_R_3 3
//#define AK4490EQ_ATT_R_3_default BIT_HIGH
//#define AK4490EQ_ATT_R_2 2
//#define AK4490EQ_ATT_R_2_default BIT_HIGH
//#define AK4490EQ_ATT_R_1 1
//#define AK4490EQ_ATT_R_1_default BIT_HIGH
//#define AK4490EQ_ATT_R_0 0
//#define AK4490EQ_ATT_R_0_default BIT_HIGH
////05H
//#define AK4490EQ_REG_CTRL_4 5
//#define AK4490EQ_INV_L 7
//#define AK4490EQ_INV_L_default BIT_LOW
//#define AK4490EQ_INV_R 6
//#define AK4490EQ_INV_R_default BIT_LOW
//#define AK4490EQ_UNUSED_55 5
//#define AK4490EQ_UNUSED_55_default BIT_LOW
//#define AK4490EQ_UNUSED_54 4
//#define AK4490EQ_UNUSED_54_default BIT_LOW
//#define AK4490EQ_UNUSED_53 3
//#define AK4490EQ_UNUSED_53_default BIT_LOW
//#define AK4490EQ_UNUSED_52 2
//#define AK4490EQ_UNUSED_52_default BIT_LOW
//#define AK4490EQ_DFS_2 1
//#define AK4490EQ_DFS_2_default BIT_LOW
//#define AK4490EQ_DFTHR 0
//#define AK4490EQ_DFTHR_default BIT_LOW
////06H
//#define AK4490EQ_REG_DSD_1 6
//#define AK4490EQ_DDM 7
//#define AK4490EQ_DDM_default BIT_LOW
//#define AK4490EQ_DML 6
//#define AK4490EQ_DML_default BIT_LOW
//#define AK4490EQ_DMR 5
//#define AK4490EQ_DMR_default BIT_LOW
//#define AK4490EQ_DMC 4
//#define AK4490EQ_DMC_default BIT_LOW
//#define AK4490EQ_DMRE 3
//#define AK4490EQ_DMRE_default BIT_LOW
//#define AK4490EQ_UNUSED_62 2
//#define AK4490EQ_UNUSED_62_default BIT_LOW
//#define AK4490EQ_DSDD 1
//#define AK4490EQ_DSDD_default BIT_LOW
//#define AK4490EQ_DSDSEL_0 0
//#define AK4490EQ_DSDSEL_0_default BIT_LOW
////07H
//#define AK4490EQ_REG_CTRL_5 7
//#define AK4490EQ_UNUSED_77 7
//#define AK4490EQ_UNUSED_77_default BIT_LOW
//#define AK4490EQ_UNUSED_76 6
//#define AK4490EQ_UNUSED_76_default BIT_LOW
//#define AK4490EQ_UNUSED_75 5
//#define AK4490EQ_UNUSED_75_default BIT_LOW
//#define AK4490EQ_UNUSED_74 4
//#define AK4490EQ_UNUSED_74_default BIT_LOW
//#define AK4490EQ_UNUSED_73 3
//#define AK4490EQ_UNUSED_73_default BIT_LOW
//#define AK4490EQ_UNUSED_72 2
//#define AK4490EQ_UNUSED_72_default BIT_LOW
//#define AK4490EQ_UNUSED_71 1
//#define AK4490EQ_UNUSED_71_default BIT_LOW
//#define AK4490EQ_SYNCE 0
//#define AK4490EQ_SYNCE_default BIT_LOW
////08H
//#define AK4490EQ_REG_CTRL_SND 8
//#define AK4490EQ_UNUSED_87 7
//#define AK4490EQ_UNUSED_87_default BIT_LOW
//#define AK4490EQ_UNUSED_86 6
//#define AK4490EQ_UNUSED_86_default BIT_LOW
//#define AK4490EQ_UNUSED_85 5
//#define AK4490EQ_UNUSED_85_default BIT_LOW
//#define AK4490EQ_UNUSED_84 4
//#define AK4490EQ_UNUSED_84_default BIT_LOW
//#define AK4490EQ_UNUSED_83 3
//#define AK4490EQ_UNUSED_83_default BIT_LOW
//#define AK4490EQ_UNUSED_82 2
//#define AK4490EQ_UNUSED_82_default BIT_LOW
//#define AK4490EQ_SC_1 1
//#define AK4490EQ_SC_1_default BIT_LOW
//#define AK4490EQ_SC_0 0
//#define AK4490EQ_SC_0_default BIT_LOW
////09H
//#define AK4490EQ_REG_DSD_2 9
//#define AK4490EQ_UNUSED_97 7
//#define AK4490EQ_UNUSED_97_default BIT_LOW
//#define AK4490EQ_UNUSED_96 6
//#define AK4490EQ_UNUSED_96_default BIT_LOW
//#define AK4490EQ_UNUSED_95 5
//#define AK4490EQ_UNUSED_95_default BIT_LOW
//#define AK4490EQ_UNUSED_94 4
//#define AK4490EQ_UNUSED_94_default BIT_LOW
//#define AK4490EQ_UNUSED_93 3
//#define AK4490EQ_UNUSED_93_default BIT_LOW
//#define AK4490EQ_UNUSED_92 2
//#define AK4490EQ_UNUSED_92_default BIT_LOW
//#define AK4490EQ_DSDF 1
//#define AK4490EQ_DSDF_default BIT_LOW
//#define AK4490EQ_DSDSEL_1 0
//#define AK4490EQ_DSDSEL_1_default BIT_LOW
////AK4495SEQ OVER-RIDE
//#define AK4495SEQ_CHIP0 AK4490EQ_CHIP0
//#define AK4495SEQ_CHIP1 AK4490EQ_CHIP1
//#define AK4495SEQ_CHIP2 AK4490EQ_CHIP2
//#define AK4495SEQ_CHIP3 AK4490EQ_CHIP3
//#define AK4495SEQ_CTRL_5 AK4490EQ_REG_DSD_1
//#define AK4495SEQ_DSDD_1 2
//#define AK4495SEQ_DSDD_1_default BIT_LOW
//#define AK4495SEQ_DSDD_0 AK4490EQ_DSDD
//#define AK4495SEQ_DSDD_0_default BIT_LOW
//#define AK4495SEQ_DSDSEL AK4490EQ_DSDSEL_0
//#define AK4495SEQ_DSDSEL_default BIT_LOW
//#define AK4495SEQ_CTRL_6 AK4490EQ_REG_CTRL_5
//#define AK4495SEQ_CTRL_SND AK4490EQ_REG_CTRL_SND
//#define AK4495SEQ_SC_2 2
//#define AK4495SEQ_SC_2_default BIT_LOW
//#define AK4495SEQ_RSVD AK4490EQ_REG_DSD_2
////AK4497EQ OVER-RIDE
//#define AK4497EQ_CHIP0 AK4490EQ_CHIP0
//#define AK4497EQ_CHIP1 AK4490EQ_CHIP1
//#define AK4497EQ_CHIP2 AK4490EQ_CHIP2
//#define AK4497EQ_CHIP3 AK4490EQ_CHIP3
//#define AK4497EQ_CTRL_5 AK4490EQ_REG_DSD_1
//#define AK4497EQ_DSDD_1 2
//#define AK4497EQ_DSDD_1_default BIT_LOW
//#define AK4497EQ_DSDD_0 AK4490EQ_DSDD
//#define AK4497EQ_DSDD_0_default BIT_LOW
//#define AK4497EQ_DSDSEL AK4490EQ_DSDSEL_0
//#define AK4497EQ_DSDSEL_default BIT_LOW
//#define AK4497EQ_CTRL_6 AK4490EQ_REG_CTRL_5
//#define AK4497EQ_CTRL_SND AK4490EQ_REG_CTRL_SND
//#define AK4497EQ_SC_2 2
//#define AK4497EQ_SC_2_default BIT_LOW
//#define AK4497EQ_RSVD AK4490EQ_REG_DSD_2
//class AK449x{
//public:
void AK449x::setinit(uint8_t ChipSelect, uint8_t ChipNum) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_ACKS, AK4490EQ_ACKS_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_EXDF, AK4490EQ_EXDF_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_ECS, AK4490EQ_ECS_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_UNUSED_04, AK4490EQ_UNUSED_04_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_DIF_2, AK4490EQ_DIF_2_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_DIF_1, AK4490EQ_DIF_1_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_DIF_0, AK4490EQ_DIF_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_RSTN, AK4490EQ_RSTN_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DZFE, AK4490EQ_DZFE_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DZFM, AK4490EQ_DZFM_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_SD, AK4490EQ_SD_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DFS_1, AK4490EQ_DFS_1_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DFS_0, AK4490EQ_DFS_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DEM_1, AK4490EQ_DEM_1_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DEM_0, AK4490EQ_DEM_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_SMUTE, AK4490EQ_SMUTE_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DP, AK4490EQ_DP_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_UNUSED_26, AK4490EQ_UNUSED_26_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DCKS, AK4490EQ_DCKS_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DCKB, AK4490EQ_DCKB_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_MONO, AK4490EQ_MONO_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DZFB, AK4490EQ_DZFB_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_SELLR, AK4490EQ_SELLR_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_SSLOW, AK4490EQ_SSLOW_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_7, AK4490EQ_ATT_L_7_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_6, AK4490EQ_ATT_L_6_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_5, AK4490EQ_ATT_L_5_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_4, AK4490EQ_ATT_L_4_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_3, AK4490EQ_ATT_L_3_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_2, AK4490EQ_ATT_L_2_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_1, AK4490EQ_ATT_L_1_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_0, AK4490EQ_ATT_L_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_7, AK4490EQ_ATT_R_7_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_6, AK4490EQ_ATT_R_6_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_5, AK4490EQ_ATT_R_5_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_4, AK4490EQ_ATT_R_4_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_3, AK4490EQ_ATT_R_3_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_2, AK4490EQ_ATT_R_2_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_1, AK4490EQ_ATT_R_1_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_0, AK4490EQ_ATT_R_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_INV_L, AK4490EQ_INV_L_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_INV_R, AK4490EQ_INV_R_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_UNUSED_55, AK4490EQ_UNUSED_55_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_UNUSED_54, AK4490EQ_UNUSED_54_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_UNUSED_53, AK4490EQ_UNUSED_53_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_UNUSED_52, AK4490EQ_UNUSED_52_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_DFS_2, AK4490EQ_DFS_2_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_DFTHR, AK4490EQ_DFTHR_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DDM, AK4490EQ_DDM_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DML, AK4490EQ_DML_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DMR, AK4490EQ_DMR_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DMC, AK4490EQ_DMC_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DMRE, AK4490EQ_DMRE_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_UNUSED_62, AK4490EQ_UNUSED_62_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DSDD, AK4490EQ_DSDD_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_DSDSEL_0, AK4490EQ_DSDSEL_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_77, AK4490EQ_UNUSED_77_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_76, AK4490EQ_UNUSED_76_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_75, AK4490EQ_UNUSED_75_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_74, AK4490EQ_UNUSED_74_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_73, AK4490EQ_UNUSED_73_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_72, AK4490EQ_UNUSED_72_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_UNUSED_71, AK4490EQ_UNUSED_71_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_5], AK4490EQ_SYNCE, AK4490EQ_SYNCE_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_UNUSED_87, AK4490EQ_UNUSED_87_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_UNUSED_86, AK4490EQ_UNUSED_86_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_UNUSED_85, AK4490EQ_UNUSED_85_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_UNUSED_84, AK4490EQ_UNUSED_84_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_UNUSED_83, AK4490EQ_UNUSED_83_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_UNUSED_82, AK4490EQ_UNUSED_82_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_SC_1, AK4490EQ_SC_1_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_SC_0, AK4490EQ_SC_0_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_UNUSED_97, AK4490EQ_UNUSED_97_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_UNUSED_96, AK4490EQ_UNUSED_96_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_UNUSED_95, AK4490EQ_UNUSED_95_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_UNUSED_94, AK4490EQ_UNUSED_94_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_UNUSED_93, AK4490EQ_UNUSED_93_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_UNUSED_92, AK4490EQ_UNUSED_92_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_DSDF, AK4490EQ_DSDF_default);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_DSDSEL_1, AK4490EQ_DSDSEL_1_default);
}

////Register address: 00 (Control 1)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Reset chip without initializing registers
////|_|_|_|_|x|x|x|_| Interface mode: 16bit, 24bit, 32bit, I2S, LJ... (1)
////|_|_|x|_|_|_|_|_| External digital filter clock: 768KHz/384KHz
////|_|x|_|_|_|_|_|_| Enable/disable external digital filter mode
////|x|_|_|_|_|_|_|_| Master Clock frequency Setting: auto/manual (2)(3)
void AK449x::TimingReset(uint8_t ChipSelect, uint8_t ChipNum) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_RSTN, BIT_HIGH);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_RSTN, BIT_LOW);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
}

void AK449x::AudioDataFormat(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_DIF_0, bitRead(OpMode, 0));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_DIF_1, bitRead(OpMode, 1));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_DIF_2, bitRead(OpMode, 2));
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
}

void AK449x::ExtDigitalFilterClock(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_ECS, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
}

void AK449x::ExtDigitalFilter(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_EXDF, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
}

void AK449x::AutoSetFreq(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_ACKS, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
}

////Register address: 01 (Control 2)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Mute
////|_|_|_|_|_|x|x|_| De-emphasis: Off, 32KHz, 44.1KHz, 48KHz
////|_|_|_|x|x|_|_|_| Manual setting of sampling speed: "normal", "double"... (1)
////|_|_|x|_|_|_|_|_| Short Delay/Traditional filter (Minimum/Linear phase)
////|_|x|_|_|_|_|_|_| Zero data detect mode: Separate channels or ANDed channels
////|x|_|_|_|_|_|_|_| Zero data detect ON/OFF
void AK449x::SoftMuteEnable(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_SMUTE, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2);
}

void AK449x::DeEmphasisResponse(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DIF_0, bitRead(OpMode, 0));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DIF_1, bitRead(OpMode, 1));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DIF_2, bitRead(OpMode, 2));
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2);
}

void AK449x::SamplingSpeedControl(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DFS_0, bitRead(OpMode, 0));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DFS_1, bitRead(OpMode, 1));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DFS_2, bitRead(OpMode, 2));
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2);
}

void AK449x::MinimumDelayFilter(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_SSLOW, bitRead(OpMode, 0));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_SD, bitRead(OpMode, 1));
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2);
}

void AK449x::DataZeroDetectMode(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DZFM, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2);
}

void AK449x::DataZeroDetect(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_2], AK4490EQ_DZFE, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2);
}

////Register address: 02 (Control 3)
////7 6 5 4 3 2 1 0n
////|_|_|_|_|_|_|_|x| Filter cutoff slope: fast/slow
////|_|_|_|_|_|_|x|_| MONO mode: left/right
////|_|_|_|_|_|x|_|_| Invert output pin level on zero detect
////|_|_|_|_|x|_|_|_| MONO/STEREO mode
////|_|_|_|x|_|_|_|_| DSD Data on clock falling/rising edge
////|_|x|_|_|_|_|_|_| DSD master clock frequency:512KHz/768KHz
////|x|_|_|_|_|_|_|_| PCM/DSD mode
void AK449x::LeftRight(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_SELLR, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
}

void AK449x::InvertDZF(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DZFB, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
}

void AK449x::EnableMono(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_MONO, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
}

void AK449x::InvertDCLKPolarity(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DCKB, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
}

void AK449x::MasterClockFreq768DSD(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DCKS, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
}

void AK449x::UseDSD(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_3], AK4490EQ_DP, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3);
}

////Register address: 03 (Left Channel Attenuation)
////7 6 5 4 3 2 1 0
////|x|x|x|x|x|x|x|x| Attenuation (1)
void AK449x::LchAttLevel(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_0, bitRead(OpMode, 0));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_1, bitRead(OpMode, 1));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_2, bitRead(OpMode, 2));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_3, bitRead(OpMode, 3));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_4, bitRead(OpMode, 4));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_5, bitRead(OpMode, 5));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_6, bitRead(OpMode, 6));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_L], AK4490EQ_ATT_L_7, bitRead(OpMode, 7));
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L);
}

////Register address: 04 (Right Channel Attenuation)
////7 6 5 4 3 2 1 0
////|x|x|x|x|x|x|x|x| Attenuation (1)
void AK449x::RchAttLevel(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode) {
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_0, bitRead(OpMode, 0));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_1, bitRead(OpMode, 1));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_2, bitRead(OpMode, 2));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_3, bitRead(OpMode, 3));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_4, bitRead(OpMode, 4));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_5, bitRead(OpMode, 5));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_6, bitRead(OpMode, 6));
    bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_ATT_R], AK4490EQ_ATT_R_7, bitRead(OpMode, 7));
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R);
}

////Register address: 05 (Control 4)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Super Slow filter on/off
////|_|_|_|_|_|_|x|_| Bit 3 of the manual sampling speed setting (see reg 01)
////|_|x|_|_|_|_|_|_| Left channel phase invert ON/OFF
////|x|_|_|_|_|_|_|_| Right channel phase invert ON/OFF
void AK449x::Function50(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    }*/
}

void AK449x::Function51(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    }*/
}

void AK449x::Function56(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    }*/
}

void AK449x::Function57(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_4], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4);
    }*/
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
void AK449x::Function60(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

void AK449x::Function61(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

void AK449x::Function63(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

void AK449x::Function64(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

void AK449x::Function65(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

void AK449x::Function66(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

void AK449x::Function67(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1);
    }*/
}

////Register address: 07 (Control 6)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| Synchronize ON/OFF (1)
void AK449x::Function70(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_1], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1);
    }*/
}

////Register address: 08 (Control 7)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|x|x| Sound Quality Control Setting (1)
void AK449x::Function81(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_RSTN, bitRead(OpMode, 0));
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_RSTN, bitRead(OpMode, 1));
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_RSTN, bitRead(OpMode, 0));
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_RSTN, bitRead(OpMode, 1));
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_RSTN, bitRead(OpMode, 0));
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_CTRL_SND], AK4490EQ_RSTN, bitRead(OpMode, 1));
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND);
    }*/
}

////Register address: 09 (Control 8)
////7 6 5 4 3 2 1 0
////|_|_|_|_|_|_|_|x| DSD bit 1 of sample speed selection (see also reg 5)
////|_|_|_|_|_|_|x|_| DSD filter selection when in DSD direct mode
void AK449x::Function90(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2);
    }*/
}

void AK449x::Function91(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    //if (ModelNum == 4490) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2);
    /*} else if (ModelNum == 4495) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2);
    } else if (ModelNum == 4497) {
        bitWrite(reg449x[ChipSelect][ChipNum][AK4490EQ_REG_DSD_2], AK4490EQ_RSTN, FuncEnable);
        AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2);
    }*/
}
//private:
//uint8_t reg449x[CSELECT_MAX][CHIPNUM_MAX][REGNUM];

#ifdef _SPI_H_INCLUDED

void AK449x::AK449x_SPI_Write(uint8_t ChipSelect, uint8_t ChipNum, uint8_t RegisterAddress) {
// AK449x DACs expect the register address in the upper 2 bits of the byte as Chip-Address. So shift the bits left by 6 bits:
    byte ChipNumByte = (byte) ChipNum << 6;
// AK449x DACs expect the register address in the upper 1 bits of the byte as Read/Write. So shift the bits left by 7 bits:
    byte ReadWriteByte = (byte) 1 << 7;
// AK449x DACs expect the register address in the upper 5 bits of the byte as Register-Address. So shift the bits left by 3 bits:
    byte RegisterAddressByte = (byte) RegisterAddress << 3;
// Generating the ControlData
    byte CtrlDataByte = (byte) reg449x[ChipSelect][ChipNum][RegisterAddress];
// now combine the register address and the command into one word:
    word WordToSend = ChipNum | ReadWriteByte | RegisterAddress | CtrlDataByte;
// take the chip select low to select the device:
    digitalWrite(ChipSelect, LOW);
// Send command over SPI.
    SPI.transfer16(WordToSend); //Send register location
// take the chip select high to de-select:
    digitalWrite(ChipSelect, HIGH);
}

#endif
//};