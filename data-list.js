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
import DataRow from './data-row';
/*eslint-enable no-unused-vars*/
import PropTypes from 'prop-types';

module.exports = class DataList extends React.PureComponent {
    static propTypes = {
        dataList: PropTypes.array.isRequired,
        itemLinkText: PropTypes.string.isRequired,
        resultNotFoundText: PropTypes.string.isRequired
    }

    constructor(props) {
        super(props);
    }

    render() {
        const {dataList, itemLinkText, resultNotFoundText, ...pros} = this.props; // eslint-disable-line no-unused-vars

        let rows = [],
            listTitle;

        listTitle =
            <li className="flex-list__data-row row flex-list-item">
                <div className="col-12 row flex-list-item__text">
                    <label className="flex-list-item__check">
                        <input type="checkbox" className="flex-list-item__checkbox" value="on"/><span></span>
                    </label>
                    <span className="flex-list-item__title col-2">名称</span>
                    <span className="flex-list-item__title--answer">答卷</span>
                    <span className="col-1 flex-list-item__title--state">发布状态</span>
                    <span className="col-1 flex-list-item__title--classify">分类</span>
                    <span className="flex-list-item__time--release">发布时间</span>
                    <span className="flex-list-item__time--review">最后修改时间</span>
                    <span className="flex-list-item__time--end">结束时间</span>
                    <span className="col-2 flex-list-item__title--operation">操作</span>
                </div>
            </li>;

        dataList.forEach(function (element) {
            let rowIdentify = 'row-' + element.identifier;
            rows.push(
                <DataRow
                    key={rowIdentify}
                    identifier={rowIdentify}
                    name={element.name}
                    description={element.description}
                    image={element.image}
                    url={element.url}
                    options={element.options}
                    linkText={itemLinkText}
                />
            );
        });

        return rows.length ? (
            <div className="flex-list__data-list">
                <ul className="flex-list__data-container">
                    {listTitle}
                    {rows}
                </ul>
            </div>
        ) : (
            <div className="flex-list__data-list no-result">
                <div>{resultNotFoundText}</div>
            </div>
        );
    }
};
