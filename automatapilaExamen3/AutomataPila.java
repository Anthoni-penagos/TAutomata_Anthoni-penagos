/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.automatapila;

/**
 *
 * @author antho
 */


import java.util.Stack;

public class AutomataPila {
public String derivacionConPila(String cadena) {
    Stack<String> pila = new Stack<>();
    StringBuilder resultado = new StringBuilder(); 

    pila.push("$");
    pila.push("Es"); 
    String estado = "q0";
    int indiceEntrada = 0;
    resultado.append("Cadena   |  Pila       | Estado | Transición\n");
    resultado.append("---------------------------------------------\n");

    resultado.append(imprimirTransicion(cadena, pila, estado, "ε", "ε", "q1", "$"));

    estado = "q1";
    resultado.append(imprimirTransicion(cadena, pila, estado, "ε", "ε", "q2", "Es"));

    estado = "q2";

    StringBuilder cadenaModificada = new StringBuilder(cadena);

    while (!pila.isEmpty()) {
        String topePila = pila.peek(); // Consultamos el tope de la pila
        String entradaActual = (indiceEntrada < cadena.length()) ?   String.valueOf(cadena.charAt(indiceEntrada)) : "ε";

        if (topePila.equals("Es")) {
            pila.pop();
            pila.push("En");
            pila.push("S");
            resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, "ε", "Es", "q2", "SEn"));
        } else if (topePila.equals("En")) {
            pila.pop();
            pila.push("R");
            pila.push("D");
            resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, "ε", "En", "q2", "DR"));
        } else if (topePila.equals("S")) {
            pila.pop();
            if (entradaActual.equals("+") || entradaActual.equals("-")) {
                reemplazarEnCadena(cadenaModificada, indiceEntrada, "ε");
                resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, entradaActual, "S", "q2", entradaActual));
                indiceEntrada++;
            } else {
                resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, "ε", "S", "q2", "ε"));
            }
        } else if (topePila.equals("D") && entradaActual.matches("\\d")) {
            pila.pop();
            reemplazarEnCadena(cadenaModificada, indiceEntrada, "ε");
            resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, entradaActual, "D", "q2", entradaActual));
            indiceEntrada++;
        } else if (topePila.equals("R")) {
            if (indiceEntrada < cadena.length() && Character.isDigit(cadena.charAt(indiceEntrada))) {
                pila.pop();
                pila.push("R");
                pila.push("D");
                resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, "ε", "R", "q2", "DR"));
            } else {
                pila.pop();
                resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, "ε", "R", "q2", "ε"));
            }
        } else if (topePila.equals("$") && entradaActual.equals("ε")) {
            pila.pop();
            estado = "q3"; 
            resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, "ε", "$", "q3", "ε"));
        } else {
            resultado.append(imprimirTransicion(cadenaModificada.toString(), pila, estado, entradaActual, topePila, "ERROR", "ERROR"));
            resultado.append("\nCadena no aceptada.");
            return resultado.toString();
        }
    }
    resultado.append("\nCadena aceptada.");
    return resultado.toString();
}

    private String imprimirTransicion(String cadena, Stack<String> pila, String estado, String entrada, String tope, String nuevoEstado, String accion) {
        String pilaStr = pila.isEmpty() ? "ε" : pila.toString();
        return String.format("%-9s | %-10s | %-6s | (%s, %s, %s, %s, %s)\n",
                cadena, pilaStr, estado, estado, entrada, tope, nuevoEstado, accion);
    }

    private void reemplazarEnCadena(StringBuilder cadena, int indice, String nuevoValor) {
        if (indice >= 0 && indice < cadena.length()) {
            cadena.replace(indice, indice + 1, nuevoValor);
        }
    }
}


