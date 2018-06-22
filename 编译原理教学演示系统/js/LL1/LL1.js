// LL1Judgment.JS  start


/**
 * 判断文法是否为LL(1)文法
 */

/**
 * 求能推出ε的非终结符
 *
 * @returns
 */
function getVn2null() {
  const { Vn, Vt, P } = this;
  const Vn2null = {};
  /** 对于每一个非终结符置初值为“未定”（0） */
  Vn.forEach((v) => {
    Vn2null[v] = 0;
  });
  /** 删除所有右部含有终结符的产生式 */
  const PWithoutVt = new Set(P);
  P.forEach((rule) => {
    const [, r] = rule.split('->');
    r.trim();
    const Vr = r.split('');
    for (let index = 0; index < Vr.length; index += 1) {
      const rv = Vr[index];
      if (Vt.has(rv)) {
        PWithoutVt.delete(rule);
        break;
      }
    }
  });
  /** 获取删除后产生式集合的非终结符 */
  const VnWithoutVt = new Set();
  PWithoutVt.forEach((rule) => {
    const [l] = rule.split('->');
    VnWithoutVt.add(l.trim());
  });
  /** 将缺失的非终结符置为否（false） */
  Vn.forEach((v) => {
    if (!VnWithoutVt.has(v)) {
      Vn2null[v] = false;
    }
  });
  /** 若某一非终结符的某一产生式右部为空，则将该非终结符置为是（true） */
  const PWithoutVtAndNull = new Set(PWithoutVt);
  const VnWithoutVtAndNull = new Set(VnWithoutVt);
  PWithoutVt.forEach((rule) => {
    const [l, r] = rule.split('->');
    l.trim();
    r.trim();
    if (r === 'ε') {
      VnWithoutVtAndNull.delete(l);
      Vn2null[l] = true;
    }
  });
  /** 从文法中删除该非终结符的所有产生式 */
  VnWithoutVt.forEach((v) => {
    if (!VnWithoutVtAndNull.has(v)) {
      PWithoutVt.forEach((rule) => {
        const [l] = rule.split('->');
        l.trim();
        if (l === v) {
          PWithoutVtAndNull.delete(rule);
        }
      });
    }
  });
  /** 存储每次循环结束的的规则集合 */
  const POutLoop = new Set(PWithoutVtAndNull);
  const VnOutLoop = new Set(VnWithoutVtAndNull);
  /**
   * 判断循环结束
   *
   * @returns
   */
  function finishLoop() {
    const Vn2nullValues = Object.values(Vn2null);
    if (Vn2nullValues.includes(0) && [...POutLoop].length !== 0) {
      return false;
    }
    return true;
  }
  /** 循环扫描产生式右部的每一个符号 */
  for (let index = 0; index < 100; index += 1) {
    if (finishLoop()) {
      break;
    }
    let PInLoop = new Set(POutLoop);
    /** 扫描每一个产生式 */
    PInLoop.forEach((rule) => {
      const [l, r] = rule.split('->');
      l.trim();
      r.trim();
      if (VnOutLoop.has(l)) {
        const Vr = r.split('');
        /** 扫描产生式的每一个符号 */
        for (let i = 0; i < Vr.length; i += 1) {
          const v = Vr[i];
          if (Vn.has(v)) {
            if (Vn2null[v] === true) {
              /** 若扫描到的非终结符对应的标识是true，删去该非终结符 */
              Vr[i] = '';
              if (i === Vr.length - 1) {
                const newRRule = Vr.join('');
                if (newRRule.trim()) {
                  POutLoop.delete(rule);
                  POutLoop.add(`${l}->${newRRule.trim()}`);
                } else {
                  /** 若这使产生式右部为空，则将左部非终结符对应标志改为是，并删除以该非终结符为左部的所有产生式 */
                  Vn2null[l] = true;
                  VnOutLoop.delete(l);
                }
              }
            } else if (Vn2null[v] === false) {
              /** 扫描到的非终结符对应的标识是false，则删去该产生式 */
              POutLoop.delete(rule);
              break;
            }
          } else if (v === ' ') {
            Vr[i] = '';
          }
        }
      }
    });
    /** 获取删除后产生式集合的非终结符 */
    const VnInLoop = new Set();
    POutLoop.forEach((rule) => {
      const [l] = rule.split('->');
      VnInLoop.add(l.trim());
    });
    /** 若左部失去某非终结符的所有产生式，则将该非终结符对应的标志改为否 */
    VnOutLoop.forEach((v) => {
      if (!VnInLoop.has(v)) {
        Vn2null[v] = false;
      }
    });
    /** 删去所有应该被删去的产生式 */
    PInLoop = new Set(POutLoop);
    PInLoop.forEach((rule) => {
      const [l] = rule.split('->');
      l.trim();
      if (!VnOutLoop.has(l)) {
        POutLoop.delete(rule);
      }
    });
  }
  return Vn2null;
}

/**
 * 获取某非终结符的FIRST集合
 *
 * @param {String} vn 某非终结符
 * @param {Set} Vn 非终结符集合
 * @param {Set} Vt 终结符集合
 * @param {Set} P 规则集合
 * @param {Object} Vn2null 非终结符能否推出空
 * @returns
 */
function getFIRSTSet(vn, Vn, Vt, P, Vn2null) {
  const FIRSTSet = new Set();
  const Vnstack = new Set();
  /**
   * 递归获取符号v的FIRST集合
   *
   * @param {String} lvn 产生式左部的非终结符
   */
  function getFIRSTv(lvn) {
    /** 防止无限递归 */
    if (Vnstack.has(lvn)) {
      return;
    }
    Vnstack.add(lvn);
    P.forEach((rule) => {
      const [l, r] = rule.split('->');
      l.trim();
      r.trim();
      if (l === lvn) {
        const Vr = r.split('');
        for (let i = 0; i < Vr.length; i += 1) {
          const rv = Vr[i];
          if (Vt.has(rv)) {
            FIRSTSet.add(rv);
            break;
          } else if (Vn.has(rv)) {
            getFIRSTv(rv);
            if (Vn2null[rv] === false) {
              break;
            }
          }
        }
      }
    });
    if (Vn2null[lvn] === true) {
      FIRSTSet.add('ε');
    } else {
      FIRSTSet.delete('ε');
    }
  }
  getFIRSTv(vn);
  return FIRSTSet;
}

/**
 * 获取所有非终结符的FIRST集合
 *
 * @returns
 */
function getFIRSTSets() {
  const {
    Vn, Vt, P, Vn2null,
  } = this;
  const FIRSTSets = {};
  Vn.forEach((v) => {
    FIRSTSets[v] = getFIRSTSet(v, Vn, Vt, P, Vn2null);
  });
  return FIRSTSets;
}

/**
 * 获取某非终结符的FOLLOW集合
 *
 * @param {String} vn 非终结符
 * @param {Set} Vn 非终结符集合
 * @param {Set} Vt 终结符集合
 * @param {Set} P 规则集合
 * @param {String} S 开始符
 * @param {Object} Vn2null 非终结符能否推出空
 * @param {Object} FIRST 非终结符的FIRST集合
 * @returns
 */
function getFOLLOWSet(vn, Vn, Vt, P, S, Vn2null, FIRST) {
  const FOLLOWSet = new Set();
  const Vnstack = new Set();
  /**
   * 递归获取符号v的FOLLOW集合
   *
   * @param {String} lvn 产生式左部的非终结符
   */
  function getFOLLOWv(lvn) {
    /** 防止无限递归 */
    if (Vnstack.has(lvn)) {
      return;
    }
    Vnstack.add(lvn);
    if (lvn === S) {
      FOLLOWSet.add('#');
    }
    P.forEach((rule) => {
      const [l, r] = rule.split('->');
      l.trim();
      r.trim();
      if (r.includes(lvn)) {
        const VrAll = r.split('');
        const Vr = VrAll.slice(VrAll.indexOf(lvn) + 1);
        if (!Vr[0]) {
          getFOLLOWv(l);
        } else {
          for (let i = 0; i < Vr.length; i += 1) {
            const rv = Vr[i];
            if (Vt.has(rv)) {
              FOLLOWSet.add(rv);
              break;
            } else if (Vn.has(rv)) {
              FIRST[rv].forEach((v) => {
                if (v !== 'ε') {
                  FOLLOWSet.add(v);
                }
              });
              if (Vn2null[rv] === true && i === Vr.length - 1) {
                getFOLLOWv(l);
              } else if (Vn2null[rv] === false) {
                break;
              }
            }
          }
        }
      }
    });
  }
  getFOLLOWv(vn);
  return FOLLOWSet;
}

/**
 * 获取所有非终结符的FOLLOW集合
 *
 * @returns
 */
function getFOLLOWSets() {
  const {
    Vn, Vt, P, S, Vn2null, FIRST,
  } = this;
  const FOLLOWSets = {};
  Vn.forEach((v) => {
    FOLLOWSets[v] = getFOLLOWSet(v, Vn, Vt, P, S, Vn2null, FIRST);
  });
  return FOLLOWSets;
}

/**
 * 产生式右部能否推出空
 *
 * @param {Array} Vr 产生式右部字符串
 * @param {Set} Vt 终结符集合
 * @param {Object} Vn2null 非终结符能否推出空
 * @returns
 */
function Vr2null(Vr, Vt, Vn2null) {
  if (Vr.join('') === 'ε') {
    return true;
  }
  for (let index = 0; index < Vr.length; index += 1) {
    const rv = Vr[index];
    if (Vn2null[rv] === true && index === Vr.length - 1) {
      return true;
    } else if (Vt.has(rv) || Vn2null[rv] === false) {
      return false;
    }
  }
  return false;
}

/**
 * 获取字符串的FIRST集合
 *
 * @param {Array} Vr 字符串
 * @param {Set} Vn 非终结符集合
 * @param {Set} Vt 终结符集合
 * @param {Object} Vn2null 非终结符能否推出空
 * @param {Object} FIRST 非终结符FIRST集合
 * @returns
 */
function FIRSTVr(Vr, Vn, Vt, Vn2null, FIRST) {
  const FIRSTVrSet = new Set();
  if (Vr.join('') === 'ε') {
    FIRSTVrSet.add('ε');
  } else {
    for (let index = 0; index < Vr.length; index += 1) {
      const rv = Vr[index];
      if (Vt.has(rv)) {
        FIRSTVrSet.add(rv);
        break;
      } else if (Vn.has(rv)) {
        FIRST[rv].forEach((v) => {
          if (v !== 'ε') {
            FIRSTVrSet.add(v);
          }
        });
        if (Vn2null[rv] === true && index === Vr.length - 1) {
          FIRSTVrSet.add('ε');
        } else if (Vn2null[rv] === false) {
          break;
        }
      }
    }
  }
  return FIRSTVrSet;
}

/**
 * 获取所有非终结符的SELECT集合
 *
 * @returns
 */
function getSELECTSets() {
  const {
    Vn, Vt, P, Vn2null, FIRST, FOLLOW,
  } = this;
  const SELECTSetsObject = {};
  Vn.forEach((v) => {
    SELECTSetsObject[v] = {};
  });
  P.forEach((rule) => {
    let SELECTSet;
    const [l, r] = rule.split('->');
    l.trim();
    r.trim();
    const Vr = r.split('');
    if (Vr2null(Vr, Vt, Vn2null)) {
      SELECTSet = new Set(FOLLOW[l]);
      const FIRSTSet = FIRSTVr(Vr, Vn, Vt, Vn2null, FIRST);
      FIRSTSet.forEach((v) => {
        if (v !== 'ε') {
          SELECTSet.add(v);
        }
      });
    } else {
      SELECTSet = FIRSTVr(Vr, Vn, Vt, Vn2null, FIRST);
    }
    SELECTSetsObject[l][rule] = SELECTSet;
  });
  return SELECTSetsObject;
}

/**
 * 判断是否是LL(1)文法
 *
 * @returns
 */
function getIsLL1() {
  const { SELECT } = this;
  const SELECTSetsObjectArray = Object.values(SELECT);
  for (let index = 0; index < SELECTSetsObjectArray.length; index += 1) {
    const SELECTSetsObject = SELECTSetsObjectArray[index];
    const SELECTSets = Object.values(SELECTSetsObject);
    const SELECTArray = [];
    SELECTSets.forEach((SELECTSet) => {
      SELECTSet.forEach((v) => {
        SELECTArray.push(v);
      });
    });
    const SELECTSet = new Set(SELECTArray);
    if (SELECTArray.length !== [...SELECTSet].length) {
      return false;
    }
  }
  return true;
}

/**
 * 判断文法是否为LL(1)文法
 *
 * @param {any} Vn 非终结符集合
 * @param {any} Vt 终结符集合
 * @param {any} P 规则集合
 * @param {any} S 开始符
 * @returns
 */
function LL1Judgement(Vn, Vt, P, S) {
  [this.Vn, this.Vt, this.P, this.S] = [Vn, Vt, P, S];
  const Vn2null = getVn2null();
  this.Vn2null = Vn2null;
  const FIRST = getFIRSTSets();
  this.FIRST = FIRST;
  const FOLLOW = getFOLLOWSets();
  this.FOLLOW = FOLLOW;
  const SELECT = getSELECTSets();
  this.SELECT = SELECT;
  const isLL1 = getIsLL1();
  return {
    Vn2null,
    FIRST,
    FOLLOW,
    SELECT,
    isLL1,
  };
}


// LL1Judgment.JS  end




// LL1Analysis.JS start

/**
 * 构造预测分析表
 */

/**
 * 构造预测分析表
 *
 * @returns
 */
function getLL1AnalysisTable() {
  const { Vn, Vt, SELECT } = this;
  const LL1AnalysisTable = [];
  /** 生成表头 */
  const LL1AnalysisTableHead = [...Vt];
  LL1AnalysisTableHead.push('#');
  LL1AnalysisTableHead.unshift('');
  LL1AnalysisTable.push(LL1AnalysisTableHead);
  /** 生成表体 */
  Vn.forEach((vn) => {
    const LL1AnalysisTableBody = [];
    LL1AnalysisTableHead.forEach(() => {
      LL1AnalysisTableBody.push('');
    });
    LL1AnalysisTableBody[0] = vn;
    const SELECTv = SELECT[vn];
    const rules = Object.keys(SELECTv);
    rules.forEach((rule) => {
      LL1AnalysisTableHead.forEach((v, index) => {
        if (SELECTv[rule].has(v)) {
          LL1AnalysisTableBody[index] = rule;
        }
      });
    });
    LL1AnalysisTable.push(LL1AnalysisTableBody);
  });
  return LL1AnalysisTable;
}

/**
 * 输入串分析过程
 *
 * @returns
 */
function getinputAnalysisTable() {
  console.log(this);
  const { S, input, SELECT } = this;
  const inputAnalysisTable = [];
  inputAnalysisTable.push(['步骤', '分析栈', '剩余输入串', '推导所用产生式或匹配']);
  inputAnalysisTable.push(['1', `#${S}`, `${input}#`, '']);
  for (let index = 1; index < 100; index += 1) {
    /** 一行 */
    const line = inputAnalysisTable[index];
    /** 分析栈,剩余输入串 */
    const [stack, left] = [line[1].split(''), line[2].split('')];
    /** 分析栈最后一个符号,剩余输入串的第一个符号 */
    const [lastOfStack, firstOfLeft] = [stack.pop(), left[0]];

    if (lastOfStack === '#' && firstOfLeft === '#') {
      inputAnalysisTable[index][3] = '接受';
      break;
    } else if (lastOfStack === firstOfLeft) {
      inputAnalysisTable[index][3] = `${lastOfStack}匹配`;
      left.shift();
      inputAnalysisTable.push([index + 1, stack.join(''), left.join(''), '']);
    } else {
      /** 分析栈最后一个符号的产生式 */
      const rules = Object.keys(SELECT[lastOfStack]);
      let includeV = false;
      for (let i = 0; i < rules.length; i += 1) {
        const rule = rules[i];
        if (SELECT[lastOfStack][rule].has(firstOfLeft)) {
          inputAnalysisTable[index][3] = rule;
          const [, r] = rule.split('->');
          const Vr = r.split('');
          for (let j = Vr.length - 1; j >= 0; j -= 1) {
            if (Vr[j] !== 'ε') {
              stack.push(Vr[j]);
            }
          }
          inputAnalysisTable.push([index + 1, stack.join(''), line[2], '']);
          includeV = true;
          break;
        }
      }
      if (includeV === false) {
        inputAnalysisTable[index][3] = '出错';
        return {
          isSentence: false,
          inputAnalysisTable,
        };
      }
    }
  }
  return {
    isSentence: true,
    inputAnalysisTable,
  };
}

/**
 * 构造预测分析表和生成对符号串的分析过程
 *
 * @param {any} Vn 非终结符集合
 * @param {any} Vt 终结符集合
 * @param {any} S 开始符
 * @param {any} input 输入串
 * @param {any} SELECT 非终结符的SELECT集合
 * @returns
 */
function LL1Analysis(Vn, Vt, S, input, SELECT) {
  [this.Vn, this.Vt, this.S, this.input, this.SELECT] = [Vn, Vt, S, input, SELECT];
  const LL1AnalysisTable = getLL1AnalysisTable();
  const { isSentence, inputAnalysisTable } = getinputAnalysisTable();
  return { LL1AnalysisTable, isSentence, inputAnalysisTable };
}



// LL1Analysis.JS end





//  LL1.JS start
/**
 * LL(1)方法的语法分析
 *
 * @param {any} unformattedP 不规范的规则集合
 * @param {any} input 输入串
 */
function LL1(unformattedP, input) {
  /** 非终结符 */
  const Vn = new Set();
  /** 终结符 */
  const Vt = new Set();
  /** 规则 */
  const P = new Set();
  /** 开始符 */
  const S = 'S';
  console.log(unformattedP);

  /** 标准化P */
  unformattedP.forEach((rule) => {
    const [l, r] = rule.split('->');
    l.trim();
    r.trim();
    if (r.includes('|')) {
      const rrules = r.split('|');
      rrules.forEach((rrule) => {
        P.add(`${l}->${rrule.trim()}`);
      });
    } else {
      P.add(rule);
    }
  });
  console.log(P);
  /** 获取非终结符 */
  P.forEach((rule) => {
    const [l] = rule.split('->');
    Vn.add(l.trim());
  });
  /** 获取终结符 */
  P.forEach((rule) => {
    const [, r] = rule.split('->');
    r.trim();
    const Vr = r.split('');
    Vr.forEach((v) => {
      if (!Vn.has(v) && v !== 'ε' && v !== ' ') {
        Vt.add(v);
      }
    });
  });
  /** 判断是否含有左公因子 */
  let hasLCF = false;
  Vn.forEach((vn) => {
    const LCFArray = [];
    const LCFSet = new Set();
    P.forEach((rule) => {
      const [l, r] = rule.split('->');
      l.trim();
      r.trim();
      const Vr = r.split('');
      const firstv = Vr[0];
      if (l === vn && firstv !== 'ε') {
        LCFArray.push(firstv);
        LCFSet.add(firstv);
      }
    });
    if (LCFArray.length !== [...LCFSet].length) {
      hasLCF = true;
    }
  });
  /** 判断是否有左递归 */
  let hasLRecursion = false;
  Vn.forEach((v) => {
    const VRecursion = new Set();
    function recursion(vn) {
      P.forEach((rule) => {
        const [l, r] = rule.split('->');
        l.trim();
        r.trim();
        if (l === vn) {
          const Vr = r.split('');
          const firstv = Vr[0];
          if (Vn.has(firstv)) {
            if (VRecursion.has(firstv)) {
              hasLRecursion = true;
            } else {
              VRecursion.add(firstv);
              recursion(firstv);
            }
          }
        }
      });
    }
    VRecursion.add(v);
    recursion(v);
  });

  let Vn2null;
  let FIRST;
  let FOLLOW;
  let SELECT;
  let isLL1;
  let LL1AnalysisTable = [];
  let isSentence = false;
  let inputAnalysisTable = [];

  if (hasLCF || hasLRecursion) {
    isLL1 = false;
  } else {
    /** 判断文法是否为LL(1)文法 */
    ({
      Vn2null, FIRST, FOLLOW, SELECT, isLL1,
    } = LL1Judgement(Vn, Vt, P, S));
    /** 构造预测分析表和生成对符号串的分析过程 */
    if (isLL1) {
      ({ LL1AnalysisTable, isSentence, inputAnalysisTable } = LL1Analysis(
        Vn,
        Vt,
        S,
        input,
        SELECT,
      ));
    }
  }

  return {
    hasLCF,
    hasLRecursion,
    Vn,
    Vt,
    P,
    Vn2null,
    FIRST,
    FOLLOW,
    SELECT,
    isLL1,
    LL1AnalysisTable,
    isSentence,
    inputAnalysisTable,
  };
}



//  LL1.JS end