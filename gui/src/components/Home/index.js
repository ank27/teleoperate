import React from 'react';
import { connect } from 'react-redux'
import request from 'superagent'

import {Grid, Row, Col} from 'react-bootstrap'
import FontAwesome from 'react-fontawesome'

const style = {
  div: {
    borderStyle: 'solid',
    borderColor: 'red',
    lineHeight: 30
  }
}

const Rep = ({
  onKeyDown,
}) => {
    return (
      <Grid>
        <Row>
          <Col sm={12}>
          </Col>
        </Row>

        <Row>
          <Col sm={12}>
            <div	onKeyDown={onKeyDown} 
              contentEditable={true} 
              style = {style.div} 
              value='foo'
            >
            <p> Keep focus here 
                Use arrow key for teleoperate</p>
            </div>
          </Col>
        </Row>
      </Grid>
    )
}

const dispatchProps = (dispatch) => ({
  onKeyDown(e) {
    let move = '';
    switch(e.keyCode) {
      case 38: //UP 
        move = 'z+'
        break
      case 40: //DOWN
        move = 'z-'
        break
      case 37: //LEFT
        move = 'x+'
        break
      case 39: //RIGHT
        move = 'x-'
        break
      case 34: //PAGEUP
        move = 'y+'
        break
      case 33: //PAGE DOWN
        move = 'y-'
        break
    }

    if(move=='') 
      return

    dispatch({type: 'SET_AXIS_AND_DIRECTION', payload: move});

    request
      .get('/move/')
      .query({move: move})
      .end()
  }
})
export default connect(null, dispatchProps)(Rep)

