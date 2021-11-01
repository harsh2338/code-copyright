import antlr4 from "antlr4";
import Java8Lexer from "./java/Java8Lexer.js";
import Java8Parser from "./java/Java8Parser.js";
import JavaScriptLexer from "./javascript/JavaScriptLexer.js";
import JavaScriptParser from "./javascript/JavaScriptParser.js";
import Python3Lexer from "./python/Python3Lexer.js";
import Python3Parser from "./python/Python3Parser.js";

import CPP14Lexer from "./cpp/CPP14Lexer.js";
import CPP14Parser from "./cpp/CPP14Parser.js";
import fs from "fs";

class Visitor {
  visitChildren(ctx) {
    if (!ctx) {
      return;
    }

    if (ctx.children) {
      return ctx.children.map((child) => {
        if (child.children && child.children.length != 0) {
          var ruleName = Java8Parser.ruleNames[ctx.ruleIndex];
          console.log(ruleName + " -> " + ctx.getText());
          return child.accept(this);
        } else {
          return child.getText();
        }
      });
    }
  }
}

const sourceCodeFileNames = [
  "java_source_code.java",
  "python_source_code.py",
  "cpp_source_code.cpp",
  "js_source_code.js",
];

function getJavaParser(chars) {
  const lexer = new Java8Lexer(chars);
  const tokens = new antlr4.CommonTokenStream(lexer);
  const parser = new Java8Parser(tokens);
  return parser;
}

function getJavaScriptParser(chars) {
  const lexer = new JavaScriptLexer(chars);
  const tokens = new antlr4.CommonTokenStream(lexer);
  const parser = new JavaScriptParser(tokens);
  return parser;
}

function getPythonParser(chars) {
  const lexer = new Python3Lexer(chars);
  const tokens = new antlr4.CommonTokenStream(lexer);
  const parser = new Python3Parser(tokens);
  return parser;
}

function getCPPParser(chars) {
  console.log("here");
  const lexer = new CPP14Lexer(chars);
  const tokens = new antlr4.CommonTokenStream(lexer);
  const parser = new CPP14Parser(tokens);
  return parser;
}

function printTree(languageIndex) {
  var fname = sourceCodeFileNames[languageIndex];
  const input = fs.readFileSync(`./source_code/${fname}`, "utf8");
  const chars = new antlr4.InputStream(input);
  var parser;
  switch (languageIndex) {
    case 0:
      parser = getJavaParser(chars);
      break;
    case 1:
      parser = getPythonParser(chars);
      break;
    case 2:
      parser = getCPPParser(chars);
      break;
    case 3:
      parser = getJavaScriptParser(chars);
      break;
  }
  parser.buildParseTrees = true;
  const tree = parser.program();
  tree.accept(new Visitor());
}

printTree(3);
