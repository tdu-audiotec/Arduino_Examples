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
#define AK4490EQ_CHIP0 0
#define AK4490EQ_CHIP1 1
#define AK4490EQ_CHIP2 2
#define AK4490EQ_CHIP3 3
#define AK4490EQ_REG_CTRL_1 0
#define AK4490EQ_ACKS 7
#define AK4490EQ_ACKS_default BIT_LOW
#define AK4490EQ_EXDF 6
#define AK4490EQ_EXDF_default BIT_LOW
#define AK4490EQ_ECS 5
#define AK4490EQ_ECS_default BIT_LOW
#define AK4490EQ_UNUSED_04 4
#define AK4490EQ_UNUSED_04_default BIT_LOW
#define AK4490EQ_DIF_2 3
#define AK4490EQ_DIF_2_default BIT_LOW
#define AK4490EQ_DIF_1 2
#define AK4490EQ_DIF_1_default BIT_HIGH
#define AK4490EQ_DIF_0 1
#define AK4490EQ_DIF_0_default BIT_LOW
#define AK4490EQ_RSTN 0
#define AK4490EQ_RSTN_default BIT_LOW
#define AK4490EQ_REG_CTRL_2 1
#define AK4490EQ_DZFE 7
#define AK4490EQ_DZFE_default BIT_LOW
#define AK4490EQ_DZFM 6
#define AK4490EQ_DZFM_default BIT_LOW
#define AK4490EQ_SD 5
#define AK4490EQ_SD_default BIT_HIGH
#define AK4490EQ_DFS_1 4
#define AK4490EQ_DFS_1_default BIT_LOW
#define AK4490EQ_DFS_0 3
#define AK4490EQ_DFS_0_default BIT_LOW
#define AK4490EQ_DEM_1 2
#define AK4490EQ_DEM_1_default BIT_LOW
#define AK4490EQ_DEM_0 1
#define AK4490EQ_DEM_0_default BIT_HIGH
#define AK4490EQ_SMUTE 0
#define AK4490EQ_SMUTE_default BIT_LOW
#define AK4490EQ_REG_CTRL_3 2
#define AK4490EQ_DP 7
#define AK4490EQ_DP_default BIT_LOW
#define AK4490EQ_UNUSED_26 6
#define AK4490EQ_UNUSED_26_default BIT_LOW
#define AK4490EQ_DCKS 5
#define AK4490EQ_DCKS_default BIT_LOW
#define AK4490EQ_DCKB 4
#define AK4490EQ_DCKB_default BIT_LOW
#define AK4490EQ_MONO 3
#define AK4490EQ_MONO_default BIT_LOW
#define AK4490EQ_DZFB 2
#define AK4490EQ_DZFB_default BIT_LOW
#define AK4490EQ_SELLR 1
#define AK4490EQ_SELLR_default BIT_LOW
#define AK4490EQ_SSLOW 0
#define AK4490EQ_SSLOW_default BIT_LOW
#define AK4490EQ_REG_ATT_L 3
#define AK4490EQ_ATT_L_7 7
#define AK4490EQ_ATT_L_7_default BIT_HIGH
#define AK4490EQ_ATT_L_6 6
#define AK4490EQ_ATT_L_6_default BIT_HIGH
#define AK4490EQ_ATT_L_5 5
#define AK4490EQ_ATT_L_5_default BIT_HIGH
#define AK4490EQ_ATT_L_4 4
#define AK4490EQ_ATT_L_4_default BIT_HIGH
#define AK4490EQ_ATT_L_3 3
#define AK4490EQ_ATT_L_3_default BIT_HIGH
#define AK4490EQ_ATT_L_2 2
#define AK4490EQ_ATT_L_2_default BIT_HIGH
#define AK4490EQ_ATT_L_1 1
#define AK4490EQ_ATT_L_1_default BIT_HIGH
#define AK4490EQ_ATT_L_0 0
#define AK4490EQ_ATT_L_0_default BIT_HIGH
#define AK4490EQ_REG_ATT_R 4
#define AK4490EQ_ATT_R_7 7
#define AK4490EQ_ATT_R_7_default BIT_HIGH
#define AK4490EQ_ATT_R_6 6
#define AK4490EQ_ATT_R_6_default BIT_HIGH
#define AK4490EQ_ATT_R_5 5
#define AK4490EQ_ATT_R_5_default BIT_HIGH
#define AK4490EQ_ATT_R_4 4
#define AK4490EQ_ATT_R_4_default BIT_HIGH
#define AK4490EQ_ATT_R_3 3
#define AK4490EQ_ATT_R_3_default BIT_HIGH
#define AK4490EQ_ATT_R_2 2
#define AK4490EQ_ATT_R_2_default BIT_HIGH
#define AK4490EQ_ATT_R_1 1
#define AK4490EQ_ATT_R_1_default BIT_HIGH
#define AK4490EQ_ATT_R_0 0
#define AK4490EQ_ATT_R_0_default BIT_HIGH
#define AK4490EQ_REG_CTRL_4 5
#define AK4490EQ_INV_L 7
#define AK4490EQ_INV_L_default BIT_LOW
#define AK4490EQ_INV_R 6
#define AK4490EQ_INV_R_default BIT_LOW
#define AK4490EQ_UNUSED_55 5
#define AK4490EQ_UNUSED_55_default BIT_LOW
#define AK4490EQ_UNUSED_54 4
#define AK4490EQ_UNUSED_54_default BIT_LOW
#define AK4490EQ_UNUSED_53 3
#define AK4490EQ_UNUSED_53_default BIT_LOW
#define AK4490EQ_UNUSED_52 2
#define AK4490EQ_UNUSED_52_default BIT_LOW
#define AK4490EQ_DFS_2 1
#define AK4490EQ_DFS_2_default BIT_LOW
#define AK4490EQ_DFTHR 0
#define AK4490EQ_DFTHR_default BIT_LOW
#define AK4490EQ_REG_DSD_1 6
#define AK4490EQ_DDM 7
#define AK4490EQ_DDM_default BIT_LOW
#define AK4490EQ_DML 6
#define AK4490EQ_DML_default BIT_LOW
#define AK4490EQ_DMR 5
#define AK4490EQ_DMR_default BIT_LOW
#define AK4490EQ_DMC 4
#define AK4490EQ_DMC_default BIT_LOW
#define AK4490EQ_DMRE 3
#define AK4490EQ_DMRE_default BIT_LOW
#define AK4490EQ_UNUSED_62 2
#define AK4490EQ_UNUSED_62_default BIT_LOW
#define AK4490EQ_DSDD 1
#define AK4490EQ_DSDD_default BIT_LOW
#define AK4490EQ_DSDSEL_0 0
#define AK4490EQ_DSDSEL_0_default BIT_LOW
#define AK4490EQ_REG_CTRL_5 7
#define AK4490EQ_UNUSED_77 7
#define AK4490EQ_UNUSED_77_default BIT_LOW
#define AK4490EQ_UNUSED_76 6
#define AK4490EQ_UNUSED_76_default BIT_LOW
#define AK4490EQ_UNUSED_75 5
#define AK4490EQ_UNUSED_75_default BIT_LOW
#define AK4490EQ_UNUSED_74 4
#define AK4490EQ_UNUSED_74_default BIT_LOW
#define AK4490EQ_UNUSED_73 3
#define AK4490EQ_UNUSED_73_default BIT_LOW
#define AK4490EQ_UNUSED_72 2
#define AK4490EQ_UNUSED_72_default BIT_LOW
#define AK4490EQ_UNUSED_71 1
#define AK4490EQ_UNUSED_71_default BIT_LOW
#define AK4490EQ_SYNCE 0
#define AK4490EQ_SYNCE_default BIT_LOW
#define AK4490EQ_REG_CTRL_SND 8
#define AK4490EQ_UNUSED_87 7
#define AK4490EQ_UNUSED_87_default BIT_LOW
#define AK4490EQ_UNUSED_86 6
#define AK4490EQ_UNUSED_86_default BIT_LOW
#define AK4490EQ_UNUSED_85 5
#define AK4490EQ_UNUSED_85_default BIT_LOW
#define AK4490EQ_UNUSED_84 4
#define AK4490EQ_UNUSED_84_default BIT_LOW
#define AK4490EQ_UNUSED_83 3
#define AK4490EQ_UNUSED_83_default BIT_LOW
#define AK4490EQ_UNUSED_82 2
#define AK4490EQ_UNUSED_82_default BIT_LOW
#define AK4490EQ_SC_1 1
#define AK4490EQ_SC_1_default BIT_LOW
#define AK4490EQ_SC_0 0
#define AK4490EQ_SC_0_default BIT_LOW
#define AK4490EQ_REG_DSD_2 9
#define AK4490EQ_UNUSED_97 7
#define AK4490EQ_UNUSED_97_default BIT_LOW
#define AK4490EQ_UNUSED_96 6
#define AK4490EQ_UNUSED_96_default BIT_LOW
#define AK4490EQ_UNUSED_95 5
#define AK4490EQ_UNUSED_95_default BIT_LOW
#define AK4490EQ_UNUSED_94 4
#define AK4490EQ_UNUSED_94_default BIT_LOW
#define AK4490EQ_UNUSED_93 3
#define AK4490EQ_UNUSED_93_default BIT_LOW
#define AK4490EQ_UNUSED_92 2
#define AK4490EQ_UNUSED_92_default BIT_LOW
#define AK4490EQ_DSDF 1
#define AK4490EQ_DSDF_default BIT_LOW
#define AK4490EQ_DSDSEL_1 0
#define AK4490EQ_DSDSEL_1_default BIT_LOW
#define AK4495SEQ_CHIP0 AK4490EQ_CHIP0
#define AK4495SEQ_CHIP1 AK4490EQ_CHIP1
#define AK4495SEQ_CHIP2 AK4490EQ_CHIP2
#define AK4495SEQ_CHIP3 AK4490EQ_CHIP3
#define AK4495SEQ_CTRL_5 AK4490EQ_REG_DSD_1
#define AK4495SEQ_DSDD_1 2
#define AK4495SEQ_DSDD_1_default BIT_LOW
#define AK4495SEQ_DSDD_0 AK4490EQ_DSDD
#define AK4495SEQ_DSDD_0_default BIT_LOW
#define AK4495SEQ_DSDSEL AK4490EQ_DSDSEL_0
#define AK4495SEQ_DSDSEL_default BIT_LOW
#define AK4495SEQ_CTRL_6 AK4490EQ_REG_CTRL_5
#define AK4495SEQ_CTRL_SND AK4490EQ_REG_CTRL_SND
#define AK4495SEQ_SC_2 2
#define AK4495SEQ_SC_2_default BIT_LOW
#define AK4495SEQ_RSVD AK4490EQ_REG_DSD_2
#define AK4497EQ_CHIP0 AK4490EQ_CHIP0
#define AK4497EQ_CHIP1 AK4490EQ_CHIP1
#define AK4497EQ_CHIP2 AK4490EQ_CHIP2
#define AK4497EQ_CHIP3 AK4490EQ_CHIP3
#define AK4497EQ_CTRL_5 AK4490EQ_REG_DSD_1
#define AK4497EQ_DSDD_1 2
#define AK4497EQ_DSDD_1_default BIT_LOW
#define AK4497EQ_DSDD_0 AK4490EQ_DSDD
#define AK4497EQ_DSDD_0_default BIT_LOW
#define AK4497EQ_DSDSEL AK4490EQ_DSDSEL_0
#define AK4497EQ_DSDSEL_default BIT_LOW
#define AK4497EQ_CTRL_6 AK4490EQ_REG_CTRL_5
#define AK4497EQ_CTRL_SND AK4490EQ_REG_CTRL_SND
#define AK4497EQ_SC_2 2
#define AK4497EQ_SC_2_default BIT_LOW
#define AK4497EQ_RSVD AK4490EQ_REG_DSD_2
class AK449x{
public:
    void setinit(uint8_t ChipSelect, uint8_t ChipNum);
    void TimingReset(uint8_t ChipSelect, uint8_t ChipNum);
    void AudioDataFormat(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode);
    void ExtDigitalFilterClock(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void ExtDigitalFilter(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void AutoSetFreq(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void SoftMuteEnable(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void DeEmphasisResponse(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode);
    void SamplingSpeedControl(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode);
    void MinimumDelayFilter(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode);
    void DataZeroDetectMode(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void DataZeroDetect(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void LeftRight(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void InvertDZF(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void EnableMono(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void InvertDCLKPolarity(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void MasterClockFreq768DSD(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void UseDSD(uint8_t ChipSelect, uint8_t ChipNum, boolean FuncEnable);
    void LchAttLevel(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode);
    void RchAttLevel(uint8_t ChipSelect, uint8_t ChipNum, uint8_t OpMode);
    void Function50(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function51(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function56(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function57(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function60(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function61(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function63(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function64(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function65(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function66(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function67(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function70(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function81(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode);
    void Function90(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
    void Function91(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable);
private:
    uint8_t reg449x[CSELECT_MAX][CHIPNUM_MAX][REGNUM];
    void AK449x_SPI_Write(uint8_t ChipSelect, uint8_t ChipNum, uint8_t RegisterAddress);
};
    
#endif
    
