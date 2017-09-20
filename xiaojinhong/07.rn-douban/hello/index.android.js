/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  AppRegistry,
  StyleSheet,
  Text,
  View,
  Button,
  Image,
  FlatList,
  ScrollView,
  SectionList,
  TouchableNativeFeedback,
  ListView,
  TextInput
} from 'react-native';
import {StackNavigator} from 'react-navigation';

const styles = StyleSheet.create({
  container: {
   flex: 1,
   paddingTop: 22
  },
  item: {
    padding: 10,
    fontSize: 18,
    height: 30,
    width:'50%',
    color :'white',
    // backgroundColor:'#6495ee',
    marginTop:10
    // borderBottomWidth:1
  },
  name:{
    fontSize:12,
    color:'black'
  },
  logo:{
    height:50,
    width:50

  }
})


// export default class FlatListBasics extends Component{
//   constructor(props){
//     super(props);
//     this.state ={dataSource:''}
//   }
//   componentWillMount(){
//     this.getMoviesFromApiAsync();
//   }
//   getMoviesFromApiAsync(){
//     return fetch('https://api.douban.com/v2/movie/coming_soon')
//     .then((response)=>response.json())
//     .then((responseJson)=>{
//       return this.setState({dataSource:responseJson.subjects});
//     })
//   }
//     render(){
//         return(
//           <View style ={styles.container}>
//           <FlatList
//           data = {this.state.dataSource}
//           renderItem={
//             ({item})=><View>
//             <Text style ={styles.item}>{item.title}</Text>
//             // <Text style ={styles.genres}>内容介绍:{item.genres[0]},{item.genres[1]},{item.genres[2]}</Text>
//             // <Text style ={styles.name}>主演:{item.casts[0].name},{item.casts[1].name},{item.casts[2].name}</Text>
//             <Image style={styles.logo} source={{uri:item.images.large}} />
//             </View>
//           }
//           />
//           </View>
//         )
//       }
// }

class PizzaTranslator extends Component {
  constructor(props) {
    super(props);
    this.state = {text: ''};
  }

  render() {
    return (
      <View style={{padding: 10}}>
        <TextInput
          style={{height: 40}}
          placeholder="Type here to translate!"
          onChangeText={(text) => this.setState({text})}
        />
        <Text style={{padding: 10, fontSize: 42}}>
          {this.state.text.split(' ').map((word) => word && '🍕').join(' ')}
        </Text>
      </View>
    );
  }
}
AppRegistry.registerComponent('hello',()=>PizzaTranslator);
