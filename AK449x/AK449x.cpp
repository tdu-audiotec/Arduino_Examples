// include the SPI library:
#include <AK449x.h>

/*
public:
 */

/*
Register address: 00 (Control 1)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|_|x| Reset chip without initializing registers
|_|_|_|_|x|x|x|_| Interface mode: 16bit, 24bit, 32bit, I2S, LJ... (1)
|_|_|x|_|_|_|_|_| External digital filter clock: 768KHz/384KHz
|_|x|_|_|_|_|_|_| Enable/disable external digital filter mode
|x|_|_|_|_|_|_|_| Master Clock frequency Setting: auto/manual (2)(3)
*/
void AK449x::TimingReset(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_RSTN, BIT_HIGH);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_1);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_RSTN, BIT_LOW);
}

void AK449x::AudioDataFormat(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    static boolean OpModeBit[8];
    AK449x::ByteToBoolean(OpMode, OpModeBit);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_DIF_0, OpModeBit[0]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_DIF_1, OpModeBit[1]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_DIF_2, OpModeBit[2]);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_1);
}

void AK449x::ExtDigitalFilterClock(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_ECS, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_1);
}

void AK449x::ExtDigitalFilter(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_EXDF, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_1);
}

void AK449x::AutoSetFreq(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_1, AK4490EQ_ACKS, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_1);
}


/*
Register address: 01 (Control 2)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|_|x| Mute
|_|_|_|_|_|x|x|_| De-emphasis: Off, 32KHz, 44.1KHz, 48KHz
|_|_|_|x|x|_|_|_| Manual setting of sampling speed: "normal", "double"... (1)
|_|_|x|_|_|_|_|_| Short Delay/Traditional filter (Minimum/Linear phase)
|_|x|_|_|_|_|_|_| Zero data detect mode: Separate channels or ANDed channels
|x|_|_|_|_|_|_|_| Zero data detect ON/OFF
*/
void AK449x::SoftMuteEnable(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_SMUTE, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_2);
}


/*
void AK449x::DeEmphasisResponse(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    static boolean OpModeBit[8];
    AK449x::ByteToBoolean(OpMode,OpModeBit);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DIF_0, OpModeBit[0]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DIF_1, OpModeBit[1]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DIF_2, OpModeBit[2]);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_2);
}
 */
void AK449x::SamplingSpeedControl(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    static boolean OpModeBit[8];
    AK449x::ByteToBoolean(OpMode, OpModeBit);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DFS_0, OpModeBit[0]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DFS_1, OpModeBit[1]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DFS_2, OpModeBit[2]);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_2);
}

void AK449x::MinimumDelayFilter(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    static boolean OpModeBit[8];
    AK449x::ByteToBoolean(OpMode, OpModeBit);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_SLOW, OpModeBit[0]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_SD, OpModeBit[1]);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_2);
}

void AK449x::DataZeroDetectMode(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DZFM, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_2);
}

void AK449x::DataZeroDetect(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DZFE, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_2);
}


/*
Register address: 02 (Control 3)
7 6 5 4 3 2 1 0n
|_|_|_|_|_|_|_|x| Filter cutoff slope: fast/slow
|_|_|_|_|_|_|x|_| MONO mode: left/right
|_|_|_|_|_|x|_|_| Invert output pin level on zero detect
|_|_|_|_|x|_|_|_| MONO/STEREO mode
|_|_|_|x|_|_|_|_| DSD Data on clock falling/rising edge
|_|x|_|_|_|_|_|_| DSD master clock frequency:512KHz/768KHz
|x|_|_|_|_|_|_|_| PCM/DSD mode
*/
void AK449x::LeftRight(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_SELLR, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
}

void AK449x::InvertDZF(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DZFB, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
}

void AK449x::EnableMono(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_MONO, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
}

void AK449x::InvertDCLKPolarity(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DCKB, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
}

void AK449x::MasterClockFreq768DSD(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DCKS, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
}

void AK449x::UseDSD(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, boolean FuncEnable) {
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DP, FuncEnable);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_CTRL_3);
}


/*
Register address: 03 (Left Channel Attenuation)
7 6 5 4 3 2 1 0
|x|x|x|x|x|x|x|x| Attenuation (1)
*/
void AK449x::LchAttLevel(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    boolean OpModeBit[8];
    AK449x::ByteToBoolean(OpMode, OpModeBit);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_0, OpModeBit[0]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_1, OpModeBit[1]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_2, OpModeBit[2]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_3, OpModeBit[3]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_4, OpModeBit[4]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_5, OpModeBit[5]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_6, OpModeBit[6]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_7, OpModeBit[7]);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_ATT_L);
}


/*
Register address: 04 (Right Channel Attenuation)
7 6 5 4 3 2 1 0
|x|x|x|x|x|x|x|x| Attenuation (1)
*/
void AK449x::RchAttLevel(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t OpMode) {
    boolean OpModeBit[8];
    AK449x::ByteToBoolean(OpMode, OpModeBit);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_0, OpModeBit[0]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_1, OpModeBit[1]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_2, OpModeBit[2]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_3, OpModeBit[3]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_4, OpModeBit[4]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_5, OpModeBit[5]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_6, OpModeBit[6]);
    AK449x::StatusWriter(ChipSelect, ChipNum, ModelNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_7, OpModeBit[7]);
    AK449x::AK449x_SPI_Write(ChipSelect, ChipNum, ModelNum, VAL_WRITE, AK4490EQ_REG_ATT_R);
}


/*
Register address: 05 (Control 4)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|_|x| Super Slow filter on/off
|_|_|_|_|_|_|x|_| Bit 3 of the manual sampling speed setting (see reg 01)
|_|x|_|_|_|_|_|_| Left channel phase invert ON/OFF
|x|_|_|_|_|_|_|_| Right channel phase invert ON/OFF
*/



/*
Register address: 06 (control 5)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|_|x| DSD bit 0 of sampling speed selection (bit 1 is in reg 9)(1)
|_|_|_|_|_|_|x|_| DSD Mode: Direct/Convert to PCM (2)
|_|_|_|_|x|_|_|_| DSD Auto-mute release when Auto-mute release is in "hold"
|_|_|_|x|_|_|_|_| Auto-mute release: Auto/hold (3)
|_|_|x|_|_|_|_|_| Right Channel DSD flag when detecting full scale signal
|_|x|_|_|_|_|_|_| Left Channel DSD flag when detecting full scale signal
|x|_|_|_|_|_|_|_| DSD AutoMute: ON/OFF (4)
*/



/*
Register address: 07 (Control 6)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|_|x| Synchronize ON/OFF (1)
*/



/*
Register address: 08 (Control 7)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|x|x| Sound Quality Control Setting (1)
*/



/*
Register address: 09 (Control 8)
7 6 5 4 3 2 1 0
|_|_|_|_|_|_|_|x| DSD bit 1 of sample speed selection (see also reg 5)
|_|_|_|_|_|_|x|_| DSD filter selection when in DSD direct mode
*/










/*
private:
 */

static const int TotalChipID = (CHIPNUM_MAX * 10) + CSELECT_MAX;
boolean CurrentStatus[TotalChipID][REGADDR][REGNUM];
boolean RegisterModified[REGADDR];
#ifdef _SPI_H_INCLUDED


void AK449x::ByteToBoolean(uint8_t OneByte, boolean EightBooleans[8]) {
    for (int i = 0; i < 8; i++) {
        int j = 7 - i;
        EightBooleans[j] = ((OneByte & (1 << j)) != 0);
    }
}


void AK449x::StatusWriter(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t RegisterAddress, uint8_t RegName, boolean FuncEnable) {
    static boolean RunBefore[CSELECT_MAX][4];
    if (!RunBefore[ChipSelect][ChipNum]) {
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_ACKS, AK4490EQ_ACKS_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_EXDF, AK4490EQ_EXDF_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_ECS, AK4490EQ_ECS_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, 4, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_DIF_2, AK4490EQ_DIF_2_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_DIF_1, AK4490EQ_DIF_1_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_DIF_0, AK4490EQ_DIF_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_1, AK4490EQ_RSTN, AK4490EQ_RSTN_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DZFE, AK4490EQ_DZFE_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DZFM, AK4490EQ_DZFM_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_SD, AK4490EQ_SD_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DFS_1, AK4490EQ_DFS_1_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DFS_0, AK4490EQ_DFS_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DEM_1, AK4490EQ_DEM_1_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_DEM_0, AK4490EQ_DEM_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_2, AK4490EQ_SMUTE, AK4490EQ_SMUTE_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DP, AK4490EQ_DP_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, 6, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DCKS, AK4490EQ_DCKS_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DCKB, AK4490EQ_DCKB_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_MONO, AK4490EQ_MONO_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_DZFB, AK4490EQ_DZFB_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_SELLR, AK4490EQ_SELLR_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_3, AK4490EQ_SSLOW, AK4490EQ_SSLOW_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_7, AK4490EQ_ATT_L_7_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_6, AK4490EQ_ATT_L_6_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_5, AK4490EQ_ATT_L_5_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_4, AK4490EQ_ATT_L_4_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_3, AK4490EQ_ATT_L_3_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_2, AK4490EQ_ATT_L_2_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_1, AK4490EQ_ATT_L_1_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_L, AK4490EQ_ATT_L_0, AK4490EQ_ATT_L_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_7, AK4490EQ_ATT_R_7_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_6, AK4490EQ_ATT_R_6_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_5, AK4490EQ_ATT_R_5_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_4, AK4490EQ_ATT_R_4_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_3, AK4490EQ_ATT_R_3_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_2, AK4490EQ_ATT_R_2_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_1, AK4490EQ_ATT_R_1_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_ATT_R, AK4490EQ_ATT_R_0, AK4490EQ_ATT_R_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, AK4490EQ_INV_L, AK4490EQ_INV_L_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, AK4490EQ_INV_R, AK4490EQ_INV_R_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, 5, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, 4, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, 3, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, 2, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, AK4490EQ_DFS_2, AK4490EQ_DFS_2_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_4, AK4490EQ_DFTHR, AK4490EQ_DFTHR_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DDM, AK4490EQ_DDM_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DML, AK4490EQ_DML_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DMR, AK4490EQ_DMR_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DMC, AK4490EQ_DMC_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DMRE, AK4490EQ_DMRE_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, 2, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DSDD, AK4490EQ_DSDD_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4490EQ_DSDSEL_0, AK4490EQ_DSDSEL_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 7, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 6, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 5, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 4, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 3, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 2, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, 1, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_5, AK4490EQ_SYNCE, AK4490EQ_SYNCE_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, 7, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, 6, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, 5, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, 4, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, 3, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, 2, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, AK4490EQ_SC_1, AK4490EQ_SC_1_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, AK4490EQ_SC_0, AK4490EQ_SC_0_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, 7, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, 6, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, 5, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, 4, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, 3, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, 2, BIT_LOW);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, AK4490EQ_DSDF, AK4490EQ_DSDF_init);
        AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, AK4490EQ_DSDSEL_1, AK4490EQ_DSDSEL_1_init);
        if (ModelNum == 4495) {
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4495SEQ_DSDD_1, AK4495SEQ_DSDD_1_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4495SEQ_DSDD_0, AK4495SEQ_DSDD_0_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4495SEQ_DSDSEL, AK4495SEQ_DSDSEL_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, AK4495SEQ_SC_2, AK4495SEQ_SC_2_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, AK4490EQ_DSDF, BIT_LOW);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, AK4490EQ_DSDSEL_1, BIT_LOW);
        } else if (ModelNum == 4497) {
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4497EQ_DSDD_1, AK4497EQ_DSDD_1_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4497EQ_DSDD_0, AK4497EQ_DSDD_0_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_1, AK4497EQ_DSDSEL, AK4497EQ_DSDSEL_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_CTRL_SND, AK4497EQ_SC_2, AK4497EQ_SC_2_init);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, AK4490EQ_DSDF, BIT_LOW);
            AK449x::WriteRegBit(ChipSelect, ChipNum, AK4490EQ_REG_DSD_2, AK4490EQ_DSDSEL_1, BIT_LOW);
        }
        RunBefore[ChipSelect][ChipNum] = true;
    } else {
        AK449x::WriteRegBit(ChipSelect, ChipNum, RegisterAddress, RegName, FuncEnable);
    }
}

void AK449x::WriteRegBit(uint8_t ChipSelect, uint8_t ChipNum, uint8_t RegisterAddress, uint8_t RegName, boolean FuncEnable) {
    int ChipId = AK449x::ChipID(ChipSelect, ChipNum);
    int RegArr = AK449x::RegToArr(RegName);
    CurrentStatus[ChipId][RegisterAddress][RegArr] = FuncEnable;
}

boolean AK449x::ReadRegBit(uint8_t ChipSelect, uint8_t ChipNum, uint8_t RegisterAddress, uint8_t RegName) {
    int ChipId = AK449x::ChipID(ChipSelect, ChipNum);
    int RegArr = AK449x::RegToArr(RegName);
    return (CurrentStatus[ChipId][RegisterAddress][RegArr]);
}

uint8_t AK449x::RegToArr(uint8_t RegName) {
    return (7 - RegName);
}

uint8_t AK449x::ChipID(uint8_t ChipSelect, uint8_t ChipNum) {
    return ((ChipNum * 10) + ChipSelect);
}



void AK449x::AK449x_SPI_Write(uint8_t ChipSelect, uint8_t ChipNum, int ModelNum, uint8_t ReadWrite, uint8_t RegisterAddress) {
    if (ReadWrite == VAL_WRITE) {
        if ((ChipNum < 4) && (ChipNum >= 0)) {
            boolean WriteByte[REGNUM];
            for (uint8_t i = 0; i < REGNUM; i++) {
                WriteByte[i] = AK449x::ReadRegBit(ChipSelect, ChipNum, RegisterAddress, i);
            };
// AK449x DACs expect the register address in the upper 2 bits of the byte as Chip-Address. So shift the bits left by 6 bits:
            byte ChipNumByte = (byte) ChipNum << 6;

// AK449x DACs expect the register address in the upper 1 bits of the byte as Read/Write. So shift the bits left by 7 bits:
            byte ReadWriteByte = (byte) ReadWrite << 7;

// AK449x DACs expect the register address in the upper 5 bits of the byte as Register-Address. So shift the bits left by 3 bits:
            byte RegisterAddressByte = (byte) RegisterAddress << 3;

// Generating the ControlData
            byte CtrlData = (byte) AK449x::BoolToByte(WriteByte);

// now combine the register address and the command into one word:
            word WordToSend = ChipNum | ReadWrite | RegisterAddress | CtrlData;

// take the chip select low to select the device:
            digitalWrite(ChipSelect, LOW);

// Send command over SPI.
            SPI.transfer16(WordToSend); //Send register location

// take the chip select high to de-select:
            digitalWrite(ChipSelect, HIGH);
        }
    }
};
#endif

uint8_t AK449x::BoolToByte(const boolean EightBooleans[8]) {
    uint8_t ret = 0;
    for (int i = 0; i < 8; i++) {
        if (EightBooleans[i]) {
            ret |= (1 << i);
        }
    }
    return ret;
}