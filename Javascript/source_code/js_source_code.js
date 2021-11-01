class Visitor {
  visitChildren(ctx) {
    if (!ctx) {
      return;
    }

    if (ctx.children) {
      return ctx.children.map((child) => {
        if (child.children && child.children.length != 0) {
          // var ruleName = Java8Parser.ruleNames[ctx.ruleIndex];
          // console.log(ruleName + " -> " + ctx.getText());
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
];

function getCPPParser(chars) {
  console.log("here");
  const lexer = new CPP14Lexer(chars);
  const tokens = new antlr4.CommonTokenStream(lexer);
  const parser = new CPP14Parser(tokens);
  return parser;
}
languageIndex = 2;
var fname = sourceCodeFileNames[languageIndex];
const input = fs.readFileSync(`./source_code/${fname}`, "utf8");
const chars = new antlr4.InputStream(input);
parser = getCPPParser(chars);
parser.buildParseTrees = true;
const tree = parser.classDeclaration();

tree.accept(new Visitor());
