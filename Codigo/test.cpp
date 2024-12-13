#include <gtest/gtest.h>
#include "utils.h"
#include <string>

// Prueba para validateId
TEST(TestUtils, ValidateIdTest) {
    // ID válido
    EXPECT_TRUE(Utils::validateId("1752874568"));
    
    // ID inválido por longitud
    EXPECT_FALSE(Utils::validateId("12345"));
    
    // ID inválido por error en dígitos
    EXPECT_FALSE(Utils::validateId("1752874566"));
}

// Prueba para validateEmail
TEST(TestUtils, ValidateEmailTest) {
    // Email válido
    EXPECT_TRUE(Utils::validateEmail("example@email.com"));
    
    // Email inválido
    EXPECT_FALSE(Utils::validateEmail("example.email.com"));
    
    EXPECT_FALSE(Utils::validateEmail("example@.com"));
}

// Prueba para validar placas de Ecuador
TEST(TestUtils, ValidarPlacaEcuadorTest) {
    // Placa particular válida
    EXPECT_TRUE(Utils::validarPlacaEcuador("ABC-1234"));
    
    // Placa moto válida
    EXPECT_TRUE(Utils::validarPlacaEcuador("XYZ-123"));
    
    // Placa inválida
    EXPECT_FALSE(Utils::validarPlacaEcuador("ABCD-12345"));
    
    EXPECT_FALSE(Utils::validarPlacaEcuador("DDD-1234"));
}

