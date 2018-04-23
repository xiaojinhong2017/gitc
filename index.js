/**
 * Copyright (c) 2014-present, San Wei Ju Yuan Tech Ltd. <https://www.3vjuyuan.com>
 * This file is part of swim-reformer
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * For more details:
 * https://www.3vjuyuan.com/licenses.html
 *
 * @author Team Delta <delta@3vjuyuan.com>
 * @author Team Fancy <fancy@3vjuyuan.com>
 */

/*eslint-disable no-unused-vars*/
import React from 'react';
import ReactDOM from 'react-dom';
import FlexList from './flex-list';
import 'polyfill-nodelist-foreach';
/*eslint-enable no-unused-vars*/

module.exports = class ReactFlexList {
    constructor(dataPreprocessor = null) {
        this._dataPreprocessor = dataPreprocessor;
    }

    _preprocessData(listItems) {
        return typeof this._dataPreprocessor === 'function' ? this._dataPreprocessor(listItems) : listItems;
    }

    render() {
        document.querySelectorAll('[role="react-list"]').forEach(function (element) {
            let flexListData = JSON.parse(element.querySelectorAll('[aria-label="react-list-data"]')[0].text),
                listContents = this._preprocessData(flexListData.listItems),
                listParameters = flexListData.listParameters,
                searchBoxConfig = flexListData.search,
                //filtersList = flexListData.filters,
                itemsPerPage = parseInt(listParameters.itemsPerPage),
                listTexts = listParameters.texts,
                flexListContainer = element.getElementsByClassName("react-list-container")[0],
                filtersList = {
                    "isAccessible": {
                        "label": "发布状态",
                        "options": {
                            "1": "已发布",
                            "0": "未发布"
                        }
                    }
                };
            ReactDOM.render(
                <FlexList
                    dataList={listContents}
                    filtersList={filtersList}
                    searchConfig={searchBoxConfig}
                    itemsPerPage={itemsPerPage}
                    texts={listTexts}
                />,
                flexListContainer
            );
        }, this);
    }
};
