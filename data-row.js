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

import React from 'react';  // eslint-disable-line no-unused-vars
import PropTypes from 'prop-types';

module.exports = class DataRow extends React.PureComponent {
    static propTypes = {
        identifier: PropTypes.string.isRequired,
        name: PropTypes.string.isRequired,
        description: PropTypes.string,
        image: PropTypes.string,
        url: PropTypes.string,
        options: PropTypes.object,
        linkText: PropTypes.string
    }

    constructor(props) {
        super(props);
    }

    _infoOperatingClick(e) {
        let sliceList = e.target.parentNode.parentNode.getElementsByClassName('slice__list')[0];
        if (sliceList.style.display === 'block') {
            sliceList.style.display = 'none';
        } else {
            sliceList.style.display = 'block';
        }
    }

    _sliceStatusClick(e) {
        let sliceStatus, borderCircle;
        if (e.target.classList.contains("slice__status--icon")) {
            sliceStatus = e.target;
            borderCircle = e.target.getElementsByClassName("border__circle")[0];
        } else if (e.target.classList.contains("border__circle")) {
            sliceStatus = e.target.parentNode;
            borderCircle = e.target;
        }
        if (borderCircle.classList.contains("border__circle--close")) {
            borderCircle.classList.remove("icon__left");
            borderCircle.classList.add("icon__right");
            window.setTimeout(function () {
                borderCircle.classList.remove("border__circle--close");
                borderCircle.classList.add("border__circle--open");
                sliceStatus.classList.add("slice__icon--blue");
            }, 200);

        } else if (borderCircle.classList.contains("border__circle--open")) {
            borderCircle.classList.remove("icon__right");
            borderCircle.classList.add("icon__left");
            window.setTimeout(function () {
                borderCircle.classList.remove("border__circle--open");
                borderCircle.classList.add("border__circle--close");
                sliceStatus.classList.remove("slice__icon--blue");
            }, 200);
        }
    }

    render() {
        const {identifier, name, description, image, url, options, linkText, ...pros} = this.props; // eslint-disable-line no-unused-vars

        let sliceList =
                <div className="slice__list">
                    <div className="slice__container container">
                        <div className="slice__list--icons">
                            <span className="slice__icon slice__icon--copy"></span>
                            <span className="slice__icon slice__icon--delete"></span>
                            <span className="slice__icon slice__icon--download"></span>
                        </div>
                        <div className="slice__list--status row">
                            <div className="slice__status col-6">
                                <span className="float__right">发布</span>
                            </div>
                            <div className="slice__status col-6">
                                <span className="slice__status--icon" onClick={this._sliceStatusClick.bind(this)}>
                                    <span className="border__circle border__circle--close"></span>
                                </span>

                            </div>

                            <div className="slice__status col-6">
                                <span className="float__right">历史数据</span>
                            </div>
                            <div className="slice__status col-6">
                                <span className="slice__status--icon" onClick={this._sliceStatusClick.bind(this)}>
                                    <span className="border__circle border__circle--close"></span>
                                </span>
                            </div>

                            <div className="slice__status col-6">
                                <span className="float__right">公开访问</span>
                            </div>
                            <div className="slice__status col-6">
                                <span className="slice__status--icon" onClick={this._sliceStatusClick.bind(this)}>
                                    <span className="border__circle border__circle--close"></span>
                                </span>
                            </div>
                        </div>
                    </div>
                </div>,

            itemLink =
                <a className="flex-list-item__more-info col-6 col-md-3 col-lg-2" title={name} href={url}>
                    {/*{linkText}*/}
                    <button type="button" className="button-fluid flex-list-item__info-view">
                    </button>
                    <button type="button" className="button-fluid flex-list-item__info-edit">
                    </button>
                    <button type="button" className="button-fluid flex-list-item__info-operating"
                            onClick={this._infoOperatingClick.bind(this)}>
                    </button>
                </a>;

        // imageLink =
        //     <a className="flex-list-item__image-link" title={name} href={url}>
        //         <img className="img-fluid" src={image} sizes="(min-width: 230px) 230px, 100vw" width="230"
        //              height="148" alt=""/>
        //     </a>;

        let optionsContent = [], postStatus;
        for (let optionName in options) {
            let option = options[optionName];
            for (let key in option) {
                if (optionName === 'isAccessible') {
                    postStatus =
                        <span
                            key={identifier + '-' + optionName + '-' + key}
                            className="col-1 flex-list-item__accessible"
                            value={key}>
                            {option[key]}
                        </span>;
                } else if (optionName === 'createTime') {
                    optionsContent.push(
                        <span
                            key={identifier + '-' + optionName + '-' + key}
                            className={"flex-list-item__option " + optionName}
                            value={key}>
                       {option[key]}
                    </span>
                    );
                } else if (optionName === 'publishUpTime') {
                    optionsContent.push(
                        <span
                            key={identifier + '-' + optionName + '-' + key}
                            className={"flex-list-item__option " + optionName}
                            value={key}>
                       {option[key]}
                    </span>
                    );
                } else {
                    optionsContent.push(
                        <span
                            key={identifier + '-' + optionName + '-' + key}
                            className={"flex-list-item__option " + optionName}
                            value={key}>
                       {option[key]}
                    </span>
                    );
                }
            }
        }

        return (
            <li className="flex-list__data-row row flex-list-item">
                <div className="col-12 row flex-list-item__text">
                    <label className="flex-list-item__check">
                        <input type="checkbox" className="flex-list-item__checkbox" value="on"/><span></span>
                    </label>
                    <h3 className="flex-list-item__title col-2">
                        <a title={name} href={url}>{name}</a>
                    </h3>
                    <div className="flex-list-item__answer-number">33</div>
                    {postStatus}
                    <div className="flex-list-item__classification col-1">报名表单</div>
                    {optionsContent}
                    {/*<div className="flex-list-item__teaser">*/}
                    {/*<p>{description}</p>*/}
                    {/*</div>*/}
                    {itemLink}
                    {sliceList}
                </div>
                {/*<div className="col-12 col-md-3 filter-list-item__image">*/}
                {/*{imageLink}*/}
                {/*</div>*/}
            </li>
        );
    }
};
