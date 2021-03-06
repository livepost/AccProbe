/* DO NOT EDIT THIS FILE - it is machine generated */
#include "org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText.h"


IAccessibleText* GetRef( JNIEnv *env, jobject jca){
    jclass cls = env->GetObjectClass(jca);
    jmethodID methID = env->GetMethodID(cls, "internalRef", "()I");
    return (IAccessibleText*) env->CallIntMethod(jca, methID);
}
/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetAccessibleText
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetText
  (JNIEnv * env, jobject jca){ 
	//CComBSTR str;
	IAccessibleText* ptr = GetRef(env,jca);
	CComBSTR str;
	long len=0;
	HRESULT hr = ptr->get_nCharacters(&len);
	hr  = ptr->get_text(0,len,&str);
	if(hr!=S_OK){
		putErrorCode(_T("accessibleText"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if(SUCCEEDED(hr)){
		return CreateString(env, str);
	}
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetCaretOffset
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetCaretOffset
  (JNIEnv * env, jobject jca){
	long carOffset=-1;
	HRESULT hr = GetRef(env,jca)->get_caretOffset(&carOffset);
	if(hr!=S_OK){
		putErrorCode(_T("caretOffset"), CAccessible::getHRESULTString(hr), env, jca);
	}
	return carOffset;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetAttributes
 * Signature: (J)Lorg/ally/accservice/core/win32/ia2/IA2TextSegment;
 */
JNIEXPORT jobject JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetAttributes
  (JNIEnv * env, jobject jca, jlong offset ){
	IAccessibleText* ptr = GetRef(env,jca);
	BSTR text;
	long  start=0;
	long end=0;
	HRESULT hr = ptr->get_attributes(offset,&start,&end,&text);
	if(hr!=S_OK){
		putErrorCode(_T("attributes"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		jobject jobj = createIA2Segment(env, start,end, text);
		return jobj;
	}
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetSelectionCount
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetSelectionCount
  (JNIEnv * env, jobject jca){
		IAccessibleText* ptr = GetRef(env,jca);
		long ct =0;
		HRESULT hr = ptr->get_nSelections(&ct);
		if(hr!=S_OK){
			putErrorCode(_T("selectionCount"), CAccessible::getHRESULTString(hr), env, jca);
		}
		return ct;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetSelectedText
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetSelectedText
  (JNIEnv * env, jobject jca, jlong index){ 
		IAccessibleText* ptr = GetRef(env,jca);
		long start=0;
		long end =0;
		BSTR txt;
		HRESULT hr = ptr->get_selection(index,&start, &end);
		hr = ptr->get_text(start, end, &txt);
		if(hr!=S_OK){
			putErrorCode(_T("selectedText"), CAccessible::getHRESULTString(hr), env, jca);
		}
		return CreateString(env, CComBSTR(txt));
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetSelectedTextStart
  * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetSelectedTextStart
  (JNIEnv * env, jobject jca, jlong index){
		IAccessibleText* ptr = GetRef(env,jca);
		long start=0;
		long end =0;
		HRESULT hr = ptr->get_selection(index,&start, &end);
		if(hr!=S_OK){
			putErrorCode(_T("selectedTextStart"), CAccessible::getHRESULTString(hr), env, jca);
		}
		return start;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetSelectedTextEnd
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetSelectedTextEnd
  (JNIEnv * env, jobject jca, jlong index){
		IAccessibleText* ptr = GetRef(env,jca);
		long start=0;
		long end =0;
		HRESULT hr =ptr->get_selection(index,&start, &end);
		if(hr!=S_OK){
			putErrorCode(_T("selectedTextEnd"), CAccessible::getHRESULTString(hr), env, jca);
		}
		return end;
}


/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalAddSelection
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalAddSelection
  (JNIEnv * env, jobject jca, jint startOffset, jint endOffset){
	IAccessibleText* ptr = GetRef(env,jca);
	HRESULT hr = ptr->addSelection(startOffset, endOffset);
	if(hr!=S_OK){
		putErrorCode(_T("addSelection"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr))
		return true;
	else
		return false;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetCharacterBounds
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetCharacterBounds
  (JNIEnv * env, jobject jca, jint offset, jint coordType){
	IAccessibleText* ptr = GetRef(env,jca);
	long x,y,wd,ht =0;
	HRESULT hr = ptr->get_characterExtents(offset,(IA2CoordinateType)coordType, &x, &y, &wd, &ht);
	if(hr!=S_OK){
		putErrorCode(_T("characterBounds"), CAccessible::getHRESULTString(hr), env, jca);
	}

	jintArray jiarray = NULL;
	jsize size=4;
	if(SUCCEEDED(hr))
	{
		jint rect[4];
		rect[0] =x;
		rect[1]= y;
		rect[2]= wd;
		rect[3]=ht;
		jiarray = (jintArray) env->NewIntArray(size);
		env->SetIntArrayRegion(jiarray,0,size, rect);
		return jiarray;
	}
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetOffsetAtPoint
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetOffsetAtPoint
    (JNIEnv * env, jobject jca, jint x, jint y, jint coordType){
	IAccessibleText* ptr = GetRef(env,jca);
	long offset =0;
	HRESULT hr = ptr->get_offsetAtPoint(x,y,(IA2CoordinateType)coordType,&offset);
	if(hr!=S_OK){
		putErrorCode(_T("offsetAtPoint"), CAccessible::getHRESULTString(hr), env, jca);
	}
	return offset;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetTextRange
 * Signature: (II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetTextRange
  (JNIEnv * env, jobject jca, jint startOffset, jint endOffset){
	IAccessibleText* ptr = GetRef(env,jca);
	BSTR text;
	HRESULT hr = ptr->get_text(startOffset, endOffset, &text);
	if(hr!=S_OK){
		putErrorCode(_T("textRange"), CAccessible::getHRESULTString(hr), env, jca);
	}
	return CreateString(env, CComBSTR(text));
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetTextBeforeOffset
 * Signature: (II)[Ljava/lang/String;
 */
JNIEXPORT jobject JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetTextBeforeOffset
  (JNIEnv * env, jobject jca, jint offset, jint boundaryType){
	IAccessibleText* ptr = GetRef(env,jca);
	long startOffset, endOffset =0;
	BSTR text;
	HRESULT hr = ptr->get_textBeforeOffset(offset, (IA2TextBoundaryType)boundaryType, &startOffset,&endOffset, &text);
	if(hr!=S_OK){
		putErrorCode(_T("textBeforeOffset"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		jobject jobj = createIA2Segment(env, startOffset,endOffset, text);
		return jobj;
	}
	
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetTextAfterOffset
 * Signature: (II)[Ljava/lang/String;
 */
JNIEXPORT jobject JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetTextAfterOffset
  (JNIEnv * env, jobject jca, jint offset, jint boundaryType){
	IAccessibleText* ptr = GetRef(env,jca);
	long startOffset, endOffset =0;
	BSTR text;
	HRESULT hr = ptr->get_textAfterOffset(offset, (IA2TextBoundaryType)boundaryType, &startOffset,&endOffset, &text);
	if(hr!=S_OK){
		putErrorCode(_T("textAfterOffset"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		jobject jobj = createIA2Segment(env, startOffset,endOffset, text);
		return jobj;
	}
	
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetTextAtOffset
 * Signature: (II)[Ljava/lang/String;
 */
JNIEXPORT jobject JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetTextAtOffset
(JNIEnv * env, jobject jca, jint offset, jint boundaryType){
	IAccessibleText* ptr = GetRef(env,jca);
	long startOffset, endOffset =0;
	BSTR text;
	HRESULT hr = ptr->get_textAtOffset(offset, (IA2TextBoundaryType)boundaryType, &startOffset,&endOffset, &text);
	if(hr!=S_OK){
		putErrorCode(_T("TextAtOffset"), CAccessible::getHRESULTString(hr), env, jca);
	}
		if( SUCCEEDED(hr)){
		jobject jobj = createIA2Segment(env, startOffset,endOffset, text);
		return jobj;
	}
	
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalRemoveSelection
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalRemoveSelection
(JNIEnv * env, jobject jca, jint selIndex){
	IAccessibleText* ptr = GetRef(env,jca);
	HRESULT hr = ptr->removeSelection(selIndex);
	if(hr!=S_OK){
		putErrorCode(_T("removeSelection"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		return true;
	}
		return false;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalSetCaretOffset
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalSetCaretOffset
    (JNIEnv * env, jobject jca, jint offset){
	IAccessibleText* ptr = GetRef(env,jca);
	HRESULT hr = ptr->setCaretOffset(offset);
	if(hr!=S_OK){
		putErrorCode(_T("setCaretOffset"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		return true;
	}
		return false;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalSetSelection
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalSetSelection
    (JNIEnv * env, jobject jca, jint selIndex, jint startOffset, jint endOffset){
	IAccessibleText* ptr = GetRef(env,jca);
	HRESULT hr = ptr->setSelection(selIndex, startOffset,endOffset);
	if(hr!=S_OK){
		putErrorCode(_T("setSelection"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		return true;
	}
		return false;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetCharacterCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetCharacterCount
    (JNIEnv * env, jobject jca){
	IAccessibleText* ptr = GetRef(env,jca);
	long nChars =0;
	HRESULT hr = ptr->get_nCharacters(&nChars);
	if(hr!=S_OK){
		putErrorCode(_T("characterCount"), CAccessible::getHRESULTString(hr), env, jca);
	}
	return nChars;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalScrollToSubstring
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalScrollToSubstring
    (JNIEnv * env, jobject jca, jint startIndex, jint endIndex, jint scrollType){
	IAccessibleText* ptr = GetRef(env,jca);
	HRESULT hr = ptr->scrollSubstringTo(startIndex, endIndex, (IA2ScrollType)scrollType);
	
	if(hr!=S_OK){
		putErrorCode(_T("scrollToSubstring"), CAccessible::getHRESULTString(hr), env, jca);
	}
	if( SUCCEEDED(hr)){
		return true;
	}
		return false;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalScrollSubstringToPoint
 * Signature: (IIIII)Z
 */
JNIEXPORT jboolean JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalScrollSubstringToPoint
    (JNIEnv * env, jobject jca, jint startIndex, jint endIndex, jint scrollType, jint x, jint y){
	IAccessibleText* ptr = GetRef(env,jca);
	HRESULT hr = ptr->scrollSubstringToPoint(startIndex, endIndex, (IA2CoordinateType)scrollType, x, y);
	
	if(hr!=S_OK){
		putErrorCode(_T("scrollSubstringToPoint"), CAccessible::getHRESULTString(hr), env, jca);
	}else{
		return true;
	}
		return false;
}
/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetNewText
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobject JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetNewText
    (JNIEnv * env, jobject jca){
	IAccessibleText* ptr = GetRef(env,jca);
	IA2TextSegment newText;
	HRESULT hr = ptr->get_newText(&newText);
	if(hr!=S_OK){
		putErrorCode(_T("newText"), CAccessible::getHRESULTString(hr), env, jca);
	}else{
		jobject jobj = createIA2Segment(env, newText.start,newText.end, newText.text);
		return jobj;
	}
	return 0;
}

/*
 * Class:     org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText
 * Method:    internalGetOldText
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobject JNICALL Java_org_a11y_utils_accprobe_accservice_core_win32_ia2_IA2AccessibleText_internalGetOldText
    (JNIEnv * env, jobject jca){
	IAccessibleText* ptr = GetRef(env,jca);
	IA2TextSegment oldText;
	HRESULT hr = ptr->get_oldText(&oldText);
	if(hr!=S_OK){
		putErrorCode(_T("oldText"), CAccessible::getHRESULTString(hr), env, jca);
	}else{
			jobject jobj = createIA2Segment(env, oldText.start,oldText.end, oldText.text);
		return jobj;
	}
	return 0;
}

jobject  createIA2Segment(JNIEnv* env, int startOffset,int endOffset, BSTR text){
	jclass objClass;
	jmethodID ctorId;
	jobject jObj;
    objClass = env->FindClass("org/a11y/utils/accprobe/accservice/core/win32/ia2/IA2TextSegment");
	ctorId = env->GetMethodID(objClass, "<init>", "(Ljava/lang/String;II)V");
	jstring str = CreateString(env,(CComBSTR)text);
	jObj  = env->NewObject(objClass,ctorId, str, (jint)startOffset,(jint)endOffset);
	
	return jObj;
}