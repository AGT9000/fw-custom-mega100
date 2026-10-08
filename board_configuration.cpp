#include "pch.h"
#include "board_overrides.h"



static const brain_pin_e injPins[] = {
    Gpio::E9,
	Gpio::E11,
	Gpio::E10,
	Gpio::E12,
	
};

static const brain_pin_e ignPins[] = {
	Gpio::B3,
	Gpio::B4,
	Gpio::B5,
	Gpio::B6,
	
};

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

static void setInjectorPins() {
	copyArray(engineConfiguration->injectionPins, injPins);
}

static void setIgnitionPins() {
	copyArray(engineConfiguration->ignitionPins, ignPins);
}

// board-specific configuration setup
static void customBoardDefaultConfiguration() {
    // engineConfiguration->injectionPins[0] = Gpio::F13;
	engineConfiguration->injectionPins[0] = Gpio::E9;
	engineConfiguration->injectionPins[1] = Gpio::E11;
	engineConfiguration->injectionPins[2] = Gpio::E10;
	engineConfiguration->injectionPins[3] = Gpio::E12;
    // engineConfiguration->ignitionPins[0] = Gpio::E15;
	engineConfiguration->ignitionPins[0] = Gpio::B3;
	engineConfiguration->ignitionPins[1] = Gpio::B4;
	engineConfiguration->ignitionPins[2] = Gpio::B5;
	engineConfiguration->ignitionPins[0] = Gpio::B6;

	// engineConfiguration->triggerInputPins[0] = Gpio::D3;

	//setInjectorPins();
	//setIgnitionPins();
	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;

	engineConfiguration->map.sensor.hwChannel = EFI_ADC_3;

	engineConfiguration->clt.adcChannel = EFI_ADC_4;

	engineConfiguration->iat.adcChannel = EFI_ADC_0;

	engineConfiguration->tps1_1AdcChannel = EFI_ADC_10;


    	// 5.6k high side/10k low side = 1.56 ratio divider
    	engineConfiguration->analogInputDividerCoefficient = 1.47f;

    	// 6.34k high side/ 1k low side
//    	engineConfiguration->vbattDividerCoeff = (6.34 + 1) / 1;

	engineConfiguration->adcVcc = 3.3f;

	engineConfiguration->clt.config.bias_resistor = 2490;
	engineConfiguration->iat.config.bias_resistor = 2490;
	
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;

	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->sdCardCsPin = Gpio::D2;

	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->spi3sckPin = Gpio::C10;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3mosiPin = Gpio::C12;

	// Battery sense on PA0
	engineConfiguration->vbattAdcChannel = EFI_ADC_6;
	
}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;

void customBoardTsAction(uint16_t subSystem, uint16_t index);
    custom_board_ts_command = customBoardTsAction;
}
