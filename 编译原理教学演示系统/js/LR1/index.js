'use strict';

document.addEventListener('DOMContentLoaded', () => {

  const lr1ParserVis = new Lr1ParserVis(document);

  const grammarText = document.getElementById('grammar-text');
  const inputText = document.getElementById('input-text');
  const containers = {
    grammar: document.getElementById('grammar-container'),
    collection: document.getElementById('collection-container'),
    parseTable: document.getElementById('parse-table-container'),
    parseSteps: document.getElementById('parse-steps-container')
  };

  const emptyContainers = () => {
    Object.keys(containers).forEach(key => {
      containers[key].innerHTML = '';
    });
  };

  const createParser = () => {
    document.getElementById('result').className = 'result rendering';

    emptyContainers();
    lr1ParserVis.createParser(grammarText.value);
    lr1ParserVis.renderGrammar(containers.grammar);
    setTimeout(() => {
      lr1ParserVis.renderCollectionVizDot(containers.collection);
    }, 10);
    setTimeout(() => {
      document.querySelector('.about').style.display = 'none';
      document.querySelector(".result").className = 'result';
    }, 10);
    lr1ParserVis.renderParseTable(containers.parseTable);
  };

  const parse = () => {
    lr1ParserVis.parse(inputText.value);
    lr1ParserVis.renderParseSteps(containers.parseSteps);
  };


  const clear = () => {
    grammarText.value = lr1ParserVis.sampleGrammar();
    inputText.value = lr1ParserVis.sampleInput();
    emptyContainers();
    lr1ParserVis.clear();
  };


  grammarText.value = lr1ParserVis.sampleGrammar();
  inputText.value = lr1ParserVis.sampleInput();
  document.getElementById('create-parser').addEventListener('click', createParser);
  document.getElementById('parse').addEventListener('click', parse);
  document.getElementById('clear').addEventListener('click', clear);

});
