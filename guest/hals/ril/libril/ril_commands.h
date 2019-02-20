/* //guest/hals/ril/libril/ril_commands.h
**
** Copyright 2006, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
    {0, NULL},                   //none
    {RIL_REQUEST_GET_SIM_STATUS, radio_1_4::getIccCardStatusResponse},
    {RIL_REQUEST_ENTER_SIM_PIN, radio_1_4::supplyIccPinForAppResponse},
    {RIL_REQUEST_ENTER_SIM_PUK, radio_1_4::supplyIccPukForAppResponse},
    {RIL_REQUEST_ENTER_SIM_PIN2, radio_1_4::supplyIccPin2ForAppResponse},
    {RIL_REQUEST_ENTER_SIM_PUK2, radio_1_4::supplyIccPuk2ForAppResponse},
    {RIL_REQUEST_CHANGE_SIM_PIN, radio_1_4::changeIccPinForAppResponse},
    {RIL_REQUEST_CHANGE_SIM_PIN2, radio_1_4::changeIccPin2ForAppResponse},
    {RIL_REQUEST_ENTER_NETWORK_DEPERSONALIZATION, radio_1_4::supplyNetworkDepersonalizationResponse},
    {RIL_REQUEST_GET_CURRENT_CALLS, radio_1_4::getCurrentCallsResponse},
    {RIL_REQUEST_DIAL, radio_1_4::dialResponse},
    {RIL_REQUEST_GET_IMSI, radio_1_4::getIMSIForAppResponse},
    {RIL_REQUEST_HANGUP, radio_1_4::hangupConnectionResponse},
    {RIL_REQUEST_HANGUP_WAITING_OR_BACKGROUND, radio_1_4::hangupWaitingOrBackgroundResponse},
    {RIL_REQUEST_HANGUP_FOREGROUND_RESUME_BACKGROUND, radio_1_4::hangupForegroundResumeBackgroundResponse},
    {RIL_REQUEST_SWITCH_WAITING_OR_HOLDING_AND_ACTIVE, radio_1_4::switchWaitingOrHoldingAndActiveResponse},
    {RIL_REQUEST_CONFERENCE, radio_1_4::conferenceResponse},
    {RIL_REQUEST_UDUB, radio_1_4::rejectCallResponse},
    {RIL_REQUEST_LAST_CALL_FAIL_CAUSE, radio_1_4::getLastCallFailCauseResponse},
    {RIL_REQUEST_SIGNAL_STRENGTH, radio_1_4::getSignalStrengthResponse},
    {RIL_REQUEST_VOICE_REGISTRATION_STATE, radio_1_4::getVoiceRegistrationStateResponse},
    {RIL_REQUEST_DATA_REGISTRATION_STATE, radio_1_4::getDataRegistrationStateResponse},
    {RIL_REQUEST_OPERATOR, radio_1_4::getOperatorResponse},
    {RIL_REQUEST_RADIO_POWER, radio_1_4::setRadioPowerResponse},
    {RIL_REQUEST_DTMF, radio_1_4::sendDtmfResponse},
    {RIL_REQUEST_SEND_SMS, radio_1_4::sendSmsResponse},
    {RIL_REQUEST_SEND_SMS_EXPECT_MORE, radio_1_4::sendSMSExpectMoreResponse},
    {RIL_REQUEST_SETUP_DATA_CALL, radio_1_4::setupDataCallResponse},
    {RIL_REQUEST_SIM_IO, radio_1_4::iccIOForAppResponse},
    {RIL_REQUEST_SEND_USSD, radio_1_4::sendUssdResponse},
    {RIL_REQUEST_CANCEL_USSD, radio_1_4::cancelPendingUssdResponse},
    {RIL_REQUEST_GET_CLIR, radio_1_4::getClirResponse},
    {RIL_REQUEST_SET_CLIR, radio_1_4::setClirResponse},
    {RIL_REQUEST_QUERY_CALL_FORWARD_STATUS, radio_1_4::getCallForwardStatusResponse},
    {RIL_REQUEST_SET_CALL_FORWARD, radio_1_4::setCallForwardResponse},
    {RIL_REQUEST_QUERY_CALL_WAITING, radio_1_4::getCallWaitingResponse},
    {RIL_REQUEST_SET_CALL_WAITING, radio_1_4::setCallWaitingResponse},
    {RIL_REQUEST_SMS_ACKNOWLEDGE, radio_1_4::acknowledgeLastIncomingGsmSmsResponse},
    {RIL_REQUEST_GET_IMEI, NULL},
    {RIL_REQUEST_GET_IMEISV, NULL},
    {RIL_REQUEST_ANSWER, radio_1_4::acceptCallResponse},
    {RIL_REQUEST_DEACTIVATE_DATA_CALL, radio_1_4::deactivateDataCallResponse},
    {RIL_REQUEST_QUERY_FACILITY_LOCK, radio_1_4::getFacilityLockForAppResponse},
    {RIL_REQUEST_SET_FACILITY_LOCK, radio_1_4::setFacilityLockForAppResponse},
    {RIL_REQUEST_CHANGE_BARRING_PASSWORD, radio_1_4::setBarringPasswordResponse},
    {RIL_REQUEST_QUERY_NETWORK_SELECTION_MODE, radio_1_4::getNetworkSelectionModeResponse},
    {RIL_REQUEST_SET_NETWORK_SELECTION_AUTOMATIC, radio_1_4::setNetworkSelectionModeAutomaticResponse},
    {RIL_REQUEST_SET_NETWORK_SELECTION_MANUAL, radio_1_4::setNetworkSelectionModeManualResponse},
    {RIL_REQUEST_QUERY_AVAILABLE_NETWORKS , radio_1_4::getAvailableNetworksResponse},
    {RIL_REQUEST_DTMF_START, radio_1_4::startDtmfResponse},
    {RIL_REQUEST_DTMF_STOP, radio_1_4::stopDtmfResponse},
    {RIL_REQUEST_BASEBAND_VERSION, radio_1_4::getBasebandVersionResponse},
    {RIL_REQUEST_SEPARATE_CONNECTION, radio_1_4::separateConnectionResponse},
    {RIL_REQUEST_SET_MUTE, radio_1_4::setMuteResponse},
    {RIL_REQUEST_GET_MUTE, radio_1_4::getMuteResponse},
    {RIL_REQUEST_QUERY_CLIP, radio_1_4::getClipResponse},
    {RIL_REQUEST_LAST_DATA_CALL_FAIL_CAUSE, NULL},
    {RIL_REQUEST_DATA_CALL_LIST, radio_1_4::getDataCallListResponse},
    {RIL_REQUEST_RESET_RADIO, NULL},
    {RIL_REQUEST_OEM_HOOK_RAW, radio_1_4::sendRequestRawResponse},
    {RIL_REQUEST_OEM_HOOK_STRINGS, radio_1_4::sendRequestStringsResponse},
    {RIL_REQUEST_SCREEN_STATE, radio_1_4::sendDeviceStateResponse},   // Note the response function is different.
    {RIL_REQUEST_SET_SUPP_SVC_NOTIFICATION, radio_1_4::setSuppServiceNotificationsResponse},
    {RIL_REQUEST_WRITE_SMS_TO_SIM, radio_1_4::writeSmsToSimResponse},
    {RIL_REQUEST_DELETE_SMS_ON_SIM, radio_1_4::deleteSmsOnSimResponse},
    {RIL_REQUEST_SET_BAND_MODE, radio_1_4::setBandModeResponse},
    {RIL_REQUEST_QUERY_AVAILABLE_BAND_MODE, radio_1_4::getAvailableBandModesResponse},
    {RIL_REQUEST_STK_GET_PROFILE, NULL},
    {RIL_REQUEST_STK_SET_PROFILE, NULL},
    {RIL_REQUEST_STK_SEND_ENVELOPE_COMMAND, radio_1_4::sendEnvelopeResponse},
    {RIL_REQUEST_STK_SEND_TERMINAL_RESPONSE, radio_1_4::sendTerminalResponseToSimResponse},
    {RIL_REQUEST_STK_HANDLE_CALL_SETUP_REQUESTED_FROM_SIM, radio_1_4::handleStkCallSetupRequestFromSimResponse},
    {RIL_REQUEST_EXPLICIT_CALL_TRANSFER, radio_1_4::explicitCallTransferResponse},
    {RIL_REQUEST_SET_PREFERRED_NETWORK_TYPE, radio_1_4::setPreferredNetworkTypeResponse},
    {RIL_REQUEST_GET_PREFERRED_NETWORK_TYPE, radio_1_4::getPreferredNetworkTypeResponse},
    {RIL_REQUEST_GET_NEIGHBORING_CELL_IDS, radio_1_4::getNeighboringCidsResponse},
    {RIL_REQUEST_SET_LOCATION_UPDATES, radio_1_4::setLocationUpdatesResponse},
    {RIL_REQUEST_CDMA_SET_SUBSCRIPTION_SOURCE, radio_1_4::setCdmaSubscriptionSourceResponse},
    {RIL_REQUEST_CDMA_SET_ROAMING_PREFERENCE, radio_1_4::setCdmaRoamingPreferenceResponse},
    {RIL_REQUEST_CDMA_QUERY_ROAMING_PREFERENCE, radio_1_4::getCdmaRoamingPreferenceResponse},
    {RIL_REQUEST_SET_TTY_MODE, radio_1_4::setTTYModeResponse},
    {RIL_REQUEST_QUERY_TTY_MODE, radio_1_4::getTTYModeResponse},
    {RIL_REQUEST_CDMA_SET_PREFERRED_VOICE_PRIVACY_MODE, radio_1_4::setPreferredVoicePrivacyResponse},
    {RIL_REQUEST_CDMA_QUERY_PREFERRED_VOICE_PRIVACY_MODE, radio_1_4::getPreferredVoicePrivacyResponse},
    {RIL_REQUEST_CDMA_FLASH, radio_1_4::sendCDMAFeatureCodeResponse},
    {RIL_REQUEST_CDMA_BURST_DTMF, radio_1_4::sendBurstDtmfResponse},
    {RIL_REQUEST_CDMA_VALIDATE_AND_WRITE_AKEY, NULL},
    {RIL_REQUEST_CDMA_SEND_SMS, radio_1_4::sendCdmaSmsResponse},
    {RIL_REQUEST_CDMA_SMS_ACKNOWLEDGE, radio_1_4::acknowledgeLastIncomingCdmaSmsResponse},
    {RIL_REQUEST_GSM_GET_BROADCAST_SMS_CONFIG, radio_1_4::getGsmBroadcastConfigResponse},
    {RIL_REQUEST_GSM_SET_BROADCAST_SMS_CONFIG, radio_1_4::setGsmBroadcastConfigResponse},
    {RIL_REQUEST_GSM_SMS_BROADCAST_ACTIVATION, radio_1_4::setGsmBroadcastActivationResponse},
    {RIL_REQUEST_CDMA_GET_BROADCAST_SMS_CONFIG, radio_1_4::getCdmaBroadcastConfigResponse},
    {RIL_REQUEST_CDMA_SET_BROADCAST_SMS_CONFIG, radio_1_4::setCdmaBroadcastConfigResponse},
    {RIL_REQUEST_CDMA_SMS_BROADCAST_ACTIVATION, radio_1_4::setCdmaBroadcastActivationResponse},
    {RIL_REQUEST_CDMA_SUBSCRIPTION, radio_1_4::getCDMASubscriptionResponse},
    {RIL_REQUEST_CDMA_WRITE_SMS_TO_RUIM, radio_1_4::writeSmsToRuimResponse},
    {RIL_REQUEST_CDMA_DELETE_SMS_ON_RUIM, radio_1_4::deleteSmsOnRuimResponse},
    {RIL_REQUEST_DEVICE_IDENTITY, radio_1_4::getDeviceIdentityResponse},
    {RIL_REQUEST_EXIT_EMERGENCY_CALLBACK_MODE, radio_1_4::exitEmergencyCallbackModeResponse},
    {RIL_REQUEST_GET_SMSC_ADDRESS, radio_1_4::getSmscAddressResponse},
    {RIL_REQUEST_SET_SMSC_ADDRESS, radio_1_4::setSmscAddressResponse},
    {RIL_REQUEST_REPORT_SMS_MEMORY_STATUS, radio_1_4::reportSmsMemoryStatusResponse},
    {RIL_REQUEST_REPORT_STK_SERVICE_IS_RUNNING, radio_1_4::reportStkServiceIsRunningResponse},
    {RIL_REQUEST_CDMA_GET_SUBSCRIPTION_SOURCE, radio_1_4::getCdmaSubscriptionSourceResponse},
    {RIL_REQUEST_ISIM_AUTHENTICATION, radio_1_4::requestIsimAuthenticationResponse},
    {RIL_REQUEST_ACKNOWLEDGE_INCOMING_GSM_SMS_WITH_PDU, radio_1_4::acknowledgeIncomingGsmSmsWithPduResponse},
    {RIL_REQUEST_STK_SEND_ENVELOPE_WITH_STATUS, radio_1_4::sendEnvelopeWithStatusResponse},
    {RIL_REQUEST_VOICE_RADIO_TECH, radio_1_4::getVoiceRadioTechnologyResponse},
    {RIL_REQUEST_GET_CELL_INFO_LIST, radio_1_4::getCellInfoListResponse},
    {RIL_REQUEST_SET_UNSOL_CELL_INFO_LIST_RATE, radio_1_4::setCellInfoListRateResponse},
    {RIL_REQUEST_SET_INITIAL_ATTACH_APN, radio_1_4::setInitialAttachApnResponse},
    {RIL_REQUEST_IMS_REGISTRATION_STATE, radio_1_4::getImsRegistrationStateResponse},
    {RIL_REQUEST_IMS_SEND_SMS, radio_1_4::sendImsSmsResponse},
    {RIL_REQUEST_SIM_TRANSMIT_APDU_BASIC, radio_1_4::iccTransmitApduBasicChannelResponse},
    {RIL_REQUEST_SIM_OPEN_CHANNEL, radio_1_4::iccOpenLogicalChannelResponse},
    {RIL_REQUEST_SIM_CLOSE_CHANNEL, radio_1_4::iccCloseLogicalChannelResponse},
    {RIL_REQUEST_SIM_TRANSMIT_APDU_CHANNEL, radio_1_4::iccTransmitApduLogicalChannelResponse},
    {RIL_REQUEST_NV_READ_ITEM, radio_1_4::nvReadItemResponse},
    {RIL_REQUEST_NV_WRITE_ITEM, radio_1_4::nvWriteItemResponse},
    {RIL_REQUEST_NV_WRITE_CDMA_PRL, radio_1_4::nvWriteCdmaPrlResponse},
    {RIL_REQUEST_NV_RESET_CONFIG, radio_1_4::nvResetConfigResponse},
    {RIL_REQUEST_SET_UICC_SUBSCRIPTION, radio_1_4::setUiccSubscriptionResponse},
    {RIL_REQUEST_ALLOW_DATA, radio_1_4::setDataAllowedResponse},
    {RIL_REQUEST_GET_HARDWARE_CONFIG, radio_1_4::getHardwareConfigResponse},
    {RIL_REQUEST_SIM_AUTHENTICATION, radio_1_4::requestIccSimAuthenticationResponse},
    {RIL_REQUEST_GET_DC_RT_INFO, NULL},
    {RIL_REQUEST_SET_DC_RT_INFO_RATE, NULL},
    {RIL_REQUEST_SET_DATA_PROFILE, radio_1_4::setDataProfileResponse},
    {RIL_REQUEST_SHUTDOWN, radio_1_4::requestShutdownResponse},
    {RIL_REQUEST_GET_RADIO_CAPABILITY, radio_1_4::getRadioCapabilityResponse},
    {RIL_REQUEST_SET_RADIO_CAPABILITY, radio_1_4::setRadioCapabilityResponse},
    {RIL_REQUEST_START_LCE, radio_1_4::startLceServiceResponse},
    {RIL_REQUEST_STOP_LCE, radio_1_4::stopLceServiceResponse},
    {RIL_REQUEST_PULL_LCEDATA, radio_1_4::pullLceDataResponse},
    {RIL_REQUEST_GET_ACTIVITY_INFO, radio_1_4::getModemActivityInfoResponse},
    {RIL_REQUEST_SET_CARRIER_RESTRICTIONS, radio_1_4::setAllowedCarriersResponse},
    {RIL_REQUEST_GET_CARRIER_RESTRICTIONS, radio_1_4::getAllowedCarriersResponse},
    {RIL_REQUEST_SEND_DEVICE_STATE, radio_1_4::sendDeviceStateResponse},
    {RIL_REQUEST_SET_UNSOLICITED_RESPONSE_FILTER, radio_1_4::setIndicationFilterResponse},
    {RIL_REQUEST_SET_SIM_CARD_POWER, radio_1_4::setSimCardPowerResponse},
    {RIL_REQUEST_SET_CARRIER_INFO_IMSI_ENCRYPTION, radio_1_4::setCarrierInfoForImsiEncryptionResponse},
    {RIL_REQUEST_START_NETWORK_SCAN, radio_1_4::startNetworkScanResponse},
    {RIL_REQUEST_STOP_NETWORK_SCAN, radio_1_4::stopNetworkScanResponse},
    {RIL_REQUEST_START_KEEPALIVE, radio_1_4::startKeepaliveResponse},
    {RIL_REQUEST_STOP_KEEPALIVE, radio_1_4::stopKeepaliveResponse},
    {RIL_REQUEST_START_NETWORK_SCAN4, radio_1_4::startNetworkScanResponse4},
