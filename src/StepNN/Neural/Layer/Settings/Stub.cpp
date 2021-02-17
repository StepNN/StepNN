#include "BatchNormalizationLayerSettings.h"
#include "ConvLayerSettings.h"
#include "CrossEntropyLayerSettings.h"
#include "DenseLayerSettings.h"
#include "FlattenLayerSettings.h"
#include "MaxPoolingLayerSettings.h"
#include "OutputLayerSettings.h"
#include "ReLULayerSettings.h"
#include "SoftmaxLayerSettings.h"
#include "SourceLayerSettings.h"

#include "EmptySettings.h"

namespace StepNN::Neural {

const std::string BaseLayerSettings::m_defaultSettingsId = "DEFAULT_SETTINGS_ID";
const std::string EmptySettings::SETTINGS_ID = "LAYER_SETTINGS_EMPTY";

const std::string BatchNormalizationLayerSettings	::SETTINGS_ID = "LAYER_SETTINGS_BATCH_NORM";
const std::string Conv1DLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_CONV_1D";
const std::string Conv2DLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_CONV_2D";
const std::string Conv3DLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_CONV_3D";
const std::string CrossEntropyLayerSettings			::SETTINGS_ID = "LAYER_SETTINGS_CROSS_ENTROPY";
const std::string DenseLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_DENSE";
const std::string FlattenLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_FLATTEN";
const std::string MaxPooling1DLayerSettings			::SETTINGS_ID = "LAYER_SETTINGS_MAX_POOLING_1D";
const std::string MaxPooling2DLayerSettings			::SETTINGS_ID = "LAYER_SETTINGS_MAX_POOLING_2D";
const std::string MaxPooling3DLayerSettings			::SETTINGS_ID = "LAYER_SETTINGS_MAX_POOLING_3D";
const std::string OutputLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_OUTPUT";
const std::string ReLULayerSettings					::SETTINGS_ID = "LAYER_SETTINGS_RELU";
const std::string SoftmaxLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_SOFTMAX";
const std::string SourceLayerSettings				::SETTINGS_ID = "LAYER_SETTINGS_SOURCE";

}