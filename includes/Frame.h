/** @file Frame.h
 *  @brief ...
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_FRAME_H
#define JVM_CPP_FRAME_H

#include "JavaClass.h"
#include "AttributeInfo.h"
#include <stack>
#include <vector>


/**
 * @brief O Frame armazena dados e resultados parciais, para executar
 *  ligação dinâmica,retornar valores para métodos e disparar exceções.
 *  Cada frame possui seu próprio array de variáveis locais, sua pilha de
 *  operandos e uma referência para o pool de constantes da classe do método
 *  corrente.
 **/

 #define type_bool 1
 #define type_byte 2
 #define type_char 3
 #define type_short 4
 #define type_int 5
 #define type_float 6
 #define type_long 7
 #define type_double 8
 #define type_string 9
 #define type_reference 10
 #define type_array 11




/** @struct InstanciaClasse
 *  @brief Estrutura para instanciar a classe
 */
typedef struct{
    //ponteiro com o nome da classe
    std::string *name_class; 
    //ponteiro com informacoes da classe
    JavaClass *info_class; 
    //vetor com as referencias dos campos da classe
    std::map<std::string, Operand*> *campos_class;
}InstanciaClasse;


 struct Operand
 {
  u1 tag;
  union{
      u4 type_bool; /// tipo boleano
      u4 type_byte; /// tipo byte
      u4 type_char; /// tipo char
      u4 type_short; /// tipo short
      u4 type_int; /// tipo int
      u4 type_float; /// tipo float
      u8 type_long; /// tipo long
      u8 type_double; /// tipo double
      std::string* type_string; /// tipo string (ponteiro)
      ClassInstance *type_reference; /// ponteiro de instância da classe
      ArrayType *type_array;
  };
 };


class Frame {
  public:

    Frame(MethodInfo*, CpInfo*);

    CpInfo* constant_pool_reference;
    MethodInfo* method_info;
    CodeAttribute method_code;
    u4 pc;
    std::vector<u4> local_variables_array;

    std::stack<Operand> operand_stack;
    Frame* caller;
    void execute_frame();
    static void setup_instructions_func();
};

#endif
