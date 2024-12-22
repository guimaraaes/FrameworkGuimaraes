#pragma once
#include "../History/History.h"
#include "../History/Interaction.h"

enum class SearchType {
    NEXT,        // Processar apenas a próxima interação
    IGNORE_OTHER // Ignorar interações de outros componentes
};